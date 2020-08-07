#include "taskqueue.h"
#include "taskThreadManager.h"

TaskQueue::TaskQueue(TaskThreadManager* pManager_):pManager(pManager_)
{

}
void TaskQueue::insert(shared_ptr<Task> tk)
{
    std::lock_guard<std::mutex> lock(pManager->task_thread_mutex);
    task_queue.push(tk);
    pManager->task_thread_condition.notify_all();
}

shared_ptr<Task> TaskQueue::pop()
{
    //lock 二次加锁可能会导致死锁
   // std::lock_guard<std::mutex> lock(pManager->task_thread_mutex);
    shared_ptr<Task> temp = task_queue.front();
    task_queue.pop();
    return temp;
}

int TaskQueue::size()
{
    return task_queue.size();
}