#define _XOPEN_SOURCE
//
// Created by Gavin Taylor Mcroy on 10/10/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>
#include "mythreads.h"
#include "helper.h"

int interruptsAreDisabled = 0;

__attribute__((unused)) int waitingFor;

ucontext_t main_context;

int currentID = 0;

static void interruptDisable();

static void interruptEnable();

int conditionalVariable[NUM_LOCKS][CONDITIONS_PER_LOCK];

int locks[NUM_LOCKS];

void *wrapper(thFuncPtr funcPtr, void *arg) {
    interruptEnable();
    void *result = (void *) funcPtr(arg);
    threadExit(result);
    return result;
}

static void interruptDisable() {
    interruptsAreDisabled = 1;
}

static void interruptEnable() {
    interruptsAreDisabled = 0;
}

void threadInit() {
    interruptDisable();
    currentID = 0;
    Node *temp = getHead();
    temp = NULL;
    waitingFor = THREAD_ERROR;

    getcontext(&main_context);
    main_context.uc_stack.ss_size = STACK_SIZE;
    main_context.uc_stack.ss_flags = 0;

    currentID = addNode(main_context);
    getNode(currentID)->status = THREAD_RUNNING;

    for (int i = 0; i < NUM_LOCKS; i++) {
        locks[i] = THREAD_UNLOCKED;
        for (int j = 0; j < CONDITIONS_PER_LOCK; j++)
            conditionalVariable[i][j] = 0;
    }
    interruptEnable();
}


int threadCreate(thFuncPtr funcPtr, void *argPtr) {
    const int NUM_ARGS = 2;

    interruptDisable();
    ucontext_t targetContext;
    getcontext(&targetContext);

    targetContext.uc_stack.ss_sp = malloc(STACK_SIZE);
    targetContext.uc_stack.ss_size = STACK_SIZE;
    targetContext.uc_stack.ss_flags = 0;

    makecontext(&targetContext, (void (*)(void)) wrapper, NUM_ARGS, funcPtr, argPtr);

    int targetID = addNode(targetContext);
    switchThreadsStatus(currentID, targetID);

    interruptEnable();
    return targetID;
}

void threadJoin(int threadID, void **result) {
    interruptDisable();
    Node *node = getNode(threadID);

    if (!node) {
        interruptEnable();
        return;
    } else {
        while (node->status != THREAD_EXIT && node->status != THREAD_FINISHED) {
            getNode(currentID)->status = THREAD_WAITING;
            waitingFor = threadID;
            interruptEnable();
            threadYield();
            interruptDisable();
        }

        if (result) {
            *result = node->threadResult;
        }

        exitNode(threadID);
    }

    interruptEnable();
}

void threadYield() {
    interruptDisable();

    Node *targetNode = nextThread(0, 0);
    if (!targetNode) {
        interruptEnable();
        return;
    }

    Node *myNode = getNode(currentID);
    switchThreadsStatus(myNode->threadID, targetNode->threadID);
    interruptEnable();
}

void threadExit(void *result) {
    interruptDisable();
    if (currentID == MAIN_THREAD) {
        Node *node = getHead(), *temp;

        while (node) {
            temp = node->nextNode;
            if (node->threadID != MAIN_THREAD) {
                deleteNode(node->threadID);
            }
            node = temp;
        }
        exit(MAIN_THREAD);
    }
    getNode(currentID)->threadResult = result;
    getNode(currentID)->status = THREAD_FINISHED;

    interruptEnable();
    threadYield();
}

void switchThreadsStatus(int threadToChange, int changedToo) {
    if (threadToChange == changedToo) {
        return;
    }

    Node *currentNode = getNode(threadToChange);
    Node *newNode = getNode(changedToo);

    ucontext_t *newContext;
    ucontext_t *currentContext;
    newContext = &(newNode->threadContext);
    currentContext = &(currentNode->threadContext);

    if (currentNode->status == THREAD_RUNNING) {
        currentNode->status = THREAD_READY;
    }
    currentID = changedToo;
    newNode->status = THREAD_RUNNING;

    getcontext(currentContext);
    swapcontext(currentContext, newContext);

    if (currentNode->status == THREAD_READY) {
        currentNode->status = THREAD_RUNNING;
    }

    if (newNode->status == THREAD_RUNNING) {
        newNode->status = THREAD_READY;
    }

    currentID = threadToChange;
}

void threadUnlock(int lockNum) {
    interruptDisable();
    locks[lockNum] = THREAD_UNLOCKED;
    interruptEnable();
}

void threadLock(int lockNum) {
    interruptDisable();
    while (locks[lockNum] == THREAD_LOCKED) {
        interruptEnable();
        threadYield();
        interruptDisable();
    }
    locks[lockNum] = THREAD_LOCKED;
    interruptEnable();
}

void threadSignal(int lockNumber, int conditionalNum) {
    interruptDisable();
    if (conditionalVariable[lockNumber][conditionalNum] == MAIN_THREAD) {
        interruptEnable();
        return;
    }
    conditionalVariable[lockNumber][conditionalNum]--;
    Node *node = getHead();
    while (node) {
        if ((node->lockNumber == lockNumber) && (node->conditionNumber == conditionalNum)) {
            node->queuePosition--;
        }
        node = node->nextNode;
    }
    interruptEnable();
}

void threadWait(int lockNum, int conditionNum) {
    interruptDisable();
    if (locks[lockNum] != THREAD_LOCKED) {
        fprintf(stderr, "ERROR: ThreadWait called with no lock in possesion..");
        exit(THREAD_ERROR);
    }

    Node *node = getNode(currentID);
    node->lockNumber = lockNum;
    node->conditionNumber = conditionNum;
    conditionalVariable[lockNum][conditionNum]++;
    node->queuePosition = conditionalVariable[lockNum][conditionNum];

    locks[lockNum] = THREAD_UNLOCKED;
    while (node->queuePosition > MAIN_THREAD) {
        interruptEnable();
        threadYield();
        interruptDisable();
    }
    node->lockNumber = THREAD_ERROR;
    node->queuePosition = THREAD_ERROR;
    node->conditionNumber = THREAD_ERROR;

    interruptEnable();
    threadLock(lockNum);
}