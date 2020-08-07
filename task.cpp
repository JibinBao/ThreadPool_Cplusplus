#include "task.h"
Task::Task(callback cb_, void* param_):cb(cb_), param(param_)
{

}

void Task::run()
{
    cb(param);
}

Task::~Task()
{
    cout<<"任务销毁"<<endl;
}
