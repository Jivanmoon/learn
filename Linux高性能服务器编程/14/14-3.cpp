#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<wait.h>

pthread_mutex_t mutex;

//子线程运行的函数，它首先获得互斥锁mutex，然后暂停5s，再释放该互斥锁