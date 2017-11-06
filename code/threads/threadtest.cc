// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "elevatortest.h"

// testnum is set in main.cc
int testnum = 1;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
    printf("*** thread %d looped %d times priority %d\n", 
    which, num, currentThread->getPriority());
        //currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");

    Thread *t = new Thread("forked thread", 5);

    t->Fork(SimpleThread, (void*)1);
    (new Thread("forked thread", 15))->Fork(SimpleThread, (void*)2);
    SimpleThread(0);
}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------
void ThreadMax() {
    for(int i = 0; i < 129; ++i)
        Thread *t = new Thread("First Thread");
}
void ThreadPrint() {
    for(int i = 0; i < 3; ++i) {
        Thread *t = new Thread("fork thread", i);
        t->Fork(Manager -> PrintThreads, (void *)1);
    }
}
void ThreadTestID(){
    for(int i = 0; i < 5; ++i) {
        Thread *t = new Thread("Test Thread");
        printf("Thread%d's ThreadID is %d and UserID is %d\n\n",
        i,t->getThreadID(),t->getUserID());
    }
}
void
ThreadTest()
{
    switch (testnum) {
    case 1:
	ThreadTest1();
    break;
    case 2:
    ThreadMax();
    break;
    case 3:
    ThreadPrint();
    break;
    case 4:
    ThreadTestID();
    break;
    default:
	printf("No test specified.\n");
	break;
    }
}

