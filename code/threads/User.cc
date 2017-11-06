//#include "User.h"
#include "system.h"
#include "thread.h"
bool User::ThreadIsEmpty[Max_Threads] = {};
Thread *User::Threads[Max_Threads] = {};
User::User(int userid) {
    UserID = userid;
    for(int i = 0;i < Max_Threads; ++i) {
        ThreadIsEmpty[i] = true;
        Threads[i] = NULL;
    }
}
int User::AddThread(Thread* new_thread) {
    for(int i = 0;i < Max_Threads; ++i) {
        if(ThreadIsEmpty[i]) {
            ThreadIsEmpty[i] = false;
            Threads[i] = new_thread;
            return i;
        }
    }
    return -1;
}
void User::DeleteThread(Thread* old_thread) {
    if(old_thread->getThreadID() == -1)
    return;
    ThreadIsEmpty[old_thread->getThreadID()] = true;
    Threads[old_thread->getThreadID()] = NULL;
}
static void User::PrintThreads() {
    for(int i = 0; i < Max_Threads; ++i) {
        if(!ThreadIsEmpty[i]) {
            printf("UserID:%d Name:%s Id:%d Status:%s Priority:%d\n\n",
            Threads[i] -> getUserID(),Threads[i]->getName(),
            Threads[i]->getThreadID(),Threads[i]->getStatus(),Threads[i]->getPriority());
        }
    }
}
User::~User() {
    
}