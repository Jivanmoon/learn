#include "Thread.h"
#include <iostream>
using namespace std;

Thread::Thread() : autoDelete_(false)
{
    cout<<"Thread..."<<endl;
}
Thread::~Thread()
{
    cout<<"~Thread..."<<endl;
}

void Thread::Start()
{
    pthread_create(&threadId_, NULL, Thread_routine, this);
}
void Thread::Join()
{
    pthread_join(threadId_, NULL);
}

void* Thread::Thread_routine(void* arg)
{
    Thread* thread = static_cast<Thread*>(arg);
    thread->run();
    if(thread->autoDelete_)
    {
        delete thread;
    }
    return NULL;
}

void Thread::SetAutoDelete(bool autoDelete)
{
    autoDelete_ = autoDelete;
}