#include "task.h"
class TaskThreadManager;
class TaskQueue
{
    public:

     //queue<Task* > task_queue;
     queue<shared_ptr<Task> > task_queue;
     TaskThreadManager* pManager;

    public:
     TaskQueue(TaskThreadManager* pManager_);
     
     void insert(shared_ptr<Task> tk);
     
     shared_ptr<Task> pop();

     int size();
};