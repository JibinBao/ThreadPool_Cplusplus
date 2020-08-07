#include "taskThreadManager.h"
#include "threadpool.h"
#include "taskqueue.h"

TaskThreadManager::TaskThreadManager()
{
    pTask_queue  = new TaskQueue(this);
    if(!pTask_queue)
    {
        cout<<"TaskQueue constructor fail!"<<endl;
        return;
    }
    cout<<"初始任务队列长度为:"<< pTask_queue->size()<<endl;
    pThread_pool = new ThreadPool(this);
    if(!pThread_pool)
    {
        cout<<"ThreadPool constructor fail!"<<endl;
        return;
    }
    cout<<"初始线程池长度为:"<< pThread_pool->thread_pool.size()<<endl;
    pThread_pool->createThreads();
    
}

void TaskThreadManager::addTask(shared_ptr<Task> tk)
{
    pTask_queue->insert(tk);
}

void TaskThreadManager::join()
{
   pThread_pool->join(); 
}