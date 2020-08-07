#include "common.h"
class Task;
class ThreadPool;
class TaskQueue;

class TaskThreadManager
{
    public:
       void addTask(shared_ptr<Task> tk);
       TaskThreadManager();
       void join();
    public:
       ThreadPool*  pThread_pool;
       TaskQueue*   pTask_queue;
       std::mutex  task_thread_mutex;
       std::condition_variable task_thread_condition;
};