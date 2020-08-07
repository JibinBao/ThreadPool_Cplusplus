#include "common.h"
class TaskThreadManager;
class Task;

class ThreadPool
{
public:
    ThreadPool(TaskThreadManager* pManager_);
    
    void ThreadProc(void* param);
 
    void join();

    void createThreads();
    
public:

    TaskThreadManager* pManager;    
    vector<thread*> thread_pool;

};