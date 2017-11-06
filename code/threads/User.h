#include "thread.h"
#include "system.h"
#include "copyright.h"
class User{
    private:
        int UserID;
    public:
        static bool ThreadIsEmpty[Max_Threads];
        static Thread *Threads[Max_Threads];
        int AddThread(Thread* new_thread);
        void DeleteThread(Thread* old_thread);
        static void PrintThreads();
        int getUserID(){return UserID;}
        ~User();
        User(int userid);
};