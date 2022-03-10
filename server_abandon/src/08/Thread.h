#ifndef _THREAD_H_
#define _THTEAD_H_

#include <pthread.h>

class Thread
{
public:
    Thread();
    virtual ~Thread();

    void Start();
    void Join();
    void SetAutoDelete(bool autoDelete);

private:
    static void* Thread_routine(void* arg);
    virtual void run() = 0;
    pthread_t threadId_;
    bool autoDelete_;
};


#endif