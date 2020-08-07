#include "common.h"
#include "taskThreadManager.h"
#include "task.h"
#include "taskqueue.h"
#include <sys/select.h>

void runTask(void* param)
{
    int temp = *(int*)param;
    cout<<"runTask thread id is:"<<std::this_thread::get_id()<<"      "<<"parameter:"<<temp<<endl;
    sleep(1);
}


void Sleep(int ms)
{
	struct timeval delay;
	delay.tv_sec = 0;
	delay.tv_usec = ms * 1000; // 20 ms
	select(0, NULL, NULL, NULL, &delay);
}

int main()
{
    try
    {
          
       TaskThreadManager manager;
       while(1)
       {
          //这里必须new出空间，否则runTask的param为空,i为栈上变量
          int* param1 =  new int(1);
          shared_ptr<Task> pTask1(new Task(runTask,(void*)(param1)));
          //Task* pTask= new Task(runTask,(void*)(param));
          //如果insert满了怎么办，这里也应该收到一个信号，当队列满了，就不要发送了
          manager.addTask(pTask1);
          cout<<"add task"<<endl;
          /*
          This parameter can be tuned,if 100ms the queue is graduallu fully,if 200ms, push and pop are
          at balance speed, but this depend on the CPU
          */

          //Sleep(10);
       }
       
        manager.join();
        cout<<"主线程退出......"<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}