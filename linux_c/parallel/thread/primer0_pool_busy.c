#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define LEFT 30000000
#define RIGHT 30000200
#define THRNUM 4
static int num = 0;
static pthread_mutex_t mut_num = PTHREAD_MUTEX_INITIALIZER;

static void *thr_prime(void *p);

int main()
{
    int i;
    pthread_t tid[THRNUM];
    struct thr_arg_st *p;
    void *ptr;

    for (i = 0; i < THRNUM; ++i)
    {
        int err = pthread_create(tid + i, NULL, thr_prime, (void *)i);
        if (err)
        {
            fprintf(stderr, "pthread_create():%s\n", strerror(err));
            exit(1);
        }
    }

    for (i = LEFT; i <= RIGHT; ++i)
    {
        pthread_mutex_lock(&mut_num);
        while (num != 0)
        {
            pthread_mutex_unlock(&mut_num);
            sched_yield(); //出让调度器给别的线程
            pthread_mutex_lock(&mut_num);
        }
        num = i;
        pthread_mutex_unlock(&mut_num);
    }
    pthread_mutex_lock(&mut_num);
    while (num != 0)
    {
        pthread_mutex_unlock(&mut_num);
        sched_yield();
        pthread_mutex_lock(&mut_num);
    }
    num = -1;
    pthread_mutex_unlock(&mut_num);

    for (i = 0; i < THRNUM; ++i)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&mut_num);
    exit(0);
}

static void *thr_prime(void *p)
{
    while (1)
    {
        pthread_mutex_lock(&mut_num);
        while (num == 0)
        {
            pthread_mutex_unlock(&mut_num);
            sched_yield();
            pthread_mutex_lock(&mut_num);
        }
        //临界区内的跳转语句，如果跳转到临界区外，一定是先解锁后跳转
        if(num == -1) {
            pthread_mutex_unlock(&mut_num);
            break;
        }
        int i = num;
        num = 0;
        pthread_mutex_unlock(&mut_num);
        int mark = 1;
        for (int j = 2; j < i / 2; ++j)
        {
            if (i % j == 0)
            {
                mark = 0;
                break;
            }
        }
        if (mark)
            printf("[%d]%d is a primer\n", (int)p, i);
    }
    pthread_exit(p);
}
