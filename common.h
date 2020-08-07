#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "unistd.h"

using namespace std;

static const int max_thread_num=6;
static const int max_task_num=100;

typedef std::function<void (void*)> callback;


#endif
