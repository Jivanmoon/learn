#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <pthread.h>

#include "mytbf.h"

struct mytbf_st
{
    int cps;    // 每秒传输
    int burst;  // 最大限制
    int token;  // 积累传输量
    int pos;    // 记录当前令牌桶在令牌桶数组中的下标
    pthread_mutex_t mut;
};

struct mytbf_st *job[MYTBF_MAX];
static pthread_t tid_alrm;
static pthread_once_t ini_once = PTHREAD_ONCE_INIT;
static pthread_mutex_t mut_job = PTHREAD_MUTEX_INITIALIZER;

// 命名中应该体现，此函数需要加锁才能使用 xxx_unlocked()
static int get_free_pos_unlocked(void)
{
    for(int i = 0; i < MYTBF_MAX; i++)
    {
        if(job[i] == NULL)
            return i;
    }
    return -1;
}

static void module_unload(void)
{
    pthread_cancel(tid_alrm);
    pthread_join(tid_alrm, NULL);
    for(int i = 0; i < MYTBF_MAX; i++)
    {
        if(job[i] != NULL)
        {
            mytbf_destroy(job[i]);
        }
    }
    pthread_mutex_destroy(&mut_job);
}

static void *thr_alrm(void *p)
{
    while(1)
    {
        for(int i = 0; i < MYTBF_MAX; i++) {
            pthread_mutex_lock(&mut_job);
            if(job[i] != NULL)
            {
                pthread_mutex_lock(&job[i]->mut);
                job[i]->token += job[i]->cps;
                if(job[i]->token > job[i]->burst)
                    job[i]->token = job[i]->burst;
                pthread_mutex_unlock(&job[i]->mut);
            }
            pthread_mutex_unlock(&mut_job);
        }
        sleep(1);
    }

    // pthread_exit(NULL);
}

static void module_load(void)
{
    int err;
    err = pthread_create(&tid_alrm, NULL, thr_alrm, NULL);

    if(err)
    {
        fprintf(stderr, "pthread_create(): %s\n", strerror(errno));
        pthread_join(tid_alrm, NULL);
        exit(1);
    }
    
    // 因为thr_alrm线程一直在后台运行(while(1))，而pthread_join的作用是阻塞等待，故程序会一直卡在pthread_join处
    // 而不向后执行，因此这里不能使用pthread_join，而是在module_unload函数中使用cancel取消线程，接着join
    // pthread_join(tid_alrm, NULL);
    atexit(module_unload);
}

mytbf_t *mytbf_init(int cps, int burst)
{
    int pos;
    struct mytbf_st *me;
    pthread_once(&ini_once, module_load);

    me = (struct mytbf_st *)malloc(sizeof(struct mytbf_st));
    if(me == NULL) {
        return NULL;
    }
    me->cps = cps;
    me->burst = burst;
    me->token = 0;
    pthread_mutex_init(&me->mut, NULL);

    // 临界区内的跳转语句一定要记住归还锁的状态
    pthread_mutex_lock(&mut_job);
    pos = get_free_pos_unlocked();
    if(pos == -1) {
        pthread_mutex_unlock(&mut_job);
        free(me);
        return NULL;
    }

    me->pos = pos;

    job[pos] = me;
    pthread_mutex_unlock(&mut_job);
    return me;
}

static int min(const int a, const int b)
{
    return a < b ? a : b;
}

int mytbf_fetchtoken(mytbf_t *ptr, int size)
{
    struct mytbf_st *me = ptr;
    if(size <= 0)
        return -EINVAL;
    
    // 取令牌时，若桶中为空，则等待桶中有令牌再取
    pthread_mutex_lock(&me->mut);
    while(me->token <= 0)
    {
        pthread_mutex_unlock(&me->mut);
        sched_yield();
        pthread_mutex_lock(&me->mut);
    }

    int n  = min(me->token, size);

    me->token -= n;
    pthread_mutex_unlock(&me->mut);
    return n;
}

int mytbf_returntoken(mytbf_t *ptr, int size)
{
    struct mytbf_st *me;

    if(size <= 0) {
        return -EINVAL;
    }

    pthread_mutex_lock(&me->mut);
    me->token += size;

    // 令牌桶满则丢弃溢出的部分
    if(me->token > me->burst) {
        me->token = me->burst;
    }
    pthread_mutex_unlock(&me->mut);

    return size;
}

int mytbf_destroy(mytbf_t *ptr)
{
    struct mytbf_st *me = ptr;

    pthread_mutex_lock(&mut_job);
    job[me->pos] = NULL;
    pthread_mutex_unlock(&mut_job);
    
    pthread_mutex_destroy(&me->mut);
    free(me);
    return 0;
}
