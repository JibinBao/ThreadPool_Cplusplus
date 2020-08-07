#include "common.h"
#include "threadpool.h"
#include "task.h"
#include "taskqueue.h"
#include "taskThreadManager.h"

ThreadPool::ThreadPool(TaskThreadManager* pManager_): pManager(pManager_)
{
    
}

void ThreadPool::createThreads()
{
  for(int i=0; i< max_thread_num; i++)
  {
        thread_pool.push_back(new thread(std::bind(&ThreadPool::ThreadProc, this, std::placeholders::_1),this));
        //thread_pool.push_back(new thread(&ThreadPool::ThreadProc, this,this));
  }
}

void ThreadPool::ThreadProc(void* param)
{
      //这里延时1s是让task准备好
      sleep(1);
      ThreadPool* pPool= (ThreadPool*)(param);
      TaskThreadManager* pManager = pPool->pManager;
      while(1)
      {
        unique_lock<mutex> lock(pManager->task_thread_mutex);
        while(pManager->pTask_queue->size()==0)
        {
           pManager->task_thread_condition.wait(lock);
        }
        cout<<"ThreadProc队列尺寸为"<<pManager->pTask_queue->size()<<"  "<<"头部元素:"<<*(int*)(pManager->pTask_queue->task_queue.front()->param);
        shared_ptr<Task> pTask = pManager->pTask_queue->pop();
        cout<<"ThreadProc取出task成功,剩余size为"<<pManager->pTask_queue->size()<<endl;
        lock.unlock();
        cout<<"ThreadProc线程id为:"<<std::this_thread::get_id()<<endl;
        pTask->run();    
      }
}

void ThreadPool::join()
{
    for(int i=0; i< max_thread_num; i++)
    {
        thread_pool[i]->join();
    }
}
    