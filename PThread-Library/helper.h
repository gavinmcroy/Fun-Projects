//
// Created by Gavin Taylor Mcroy on 10/10/21.
//

#ifndef PROJECT2_HELPER_H
#define PROJECT2_HELPER_H

#define _XOPEN_SOURCE

typedef struct Node {
    int threadID;
    ucontext_t threadContext;
    int status;
    void *threadResult;

    int conditionNumber;
    int queuePosition;
    int lockNumber;

    struct Node *nextNode;
} Node;

typedef void *(*thFuncPtr) (void *);

void *wrapper(thFuncPtr funcPtr, void *arg);

void switchThreadsStatus(int threadToChange, int changedToo);

Node *nextThread(int currentID, int waitingFor);

Node *createNode(ucontext_t context);

int addNode(ucontext_t threadContext);

struct Node *push(ucontext_t context);

void rotateStructure();

int deleteNode(int threadID);

void exitNode(int threadID);

Node *getNode(int threadID);

Node *getHead();

#endif //PROJECT2_HELPER_H