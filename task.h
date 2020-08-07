#ifndef TASK_H
#define TASK_H
#include "common.h"
class Task
{
public:
   Task(callback cb_, void* param_);
   void run();
   ~Task();
public:
   callback cb;
   void* param;
};

#endif