#define _XOPEN_SOURCE
#include <ucontext.h>

#ifndef PROJECT2_THREAD_H
#define PROJECT2_THREAD_H

#define STACK_SIZE (16*1024)
#define NUM_LOCKS 10
#define CONDITIONS_PER_LOCK 10
#define THREAD_READY 0
#define THREAD_RUNNING 1
#define THREAD_WAITING 2
#define THREAD_FINISHED 3
#define THREAD_EXIT 4
#define THREAD_UNLOCKED 0
#define THREAD_LOCKED 1
#define THREAD_ERROR -1
#define MAIN_THREAD 0


//the type of function used to run your threads
typedef void *(*thFuncPtr)(void *);

extern void threadInit();

extern int threadCreate(thFuncPtr funcPtr, void *argPtr);

extern void threadYield();

extern void threadJoin(int threadID, void **result);

//exits the current thread -- closing the main thread, will terminate the program
extern void threadExit(void *result);

extern void threadLock(int lockNum);

extern void threadUnlock(int lockNum);

extern void threadWait(int lockNum, int conditionNum);

extern void threadSignal(int lockNumber, int conditionalNum);

__attribute__((unused)) extern int interruptsAreDisabled;

#endif //PROJECT2_THREAD_H