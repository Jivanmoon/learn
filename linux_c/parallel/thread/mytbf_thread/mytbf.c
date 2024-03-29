#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include "mytbf.h"


static struct mytbf_st *job[MYTBF_MAX];
static pthread_mutex_t mut_job = PTHREAD_MUTEX_INITIALIZER;
static unsigned int onesec = 1e6;
static pthread_t tid_alrm;
static pthread_once_t init_once = PTHREAD_ONCE_INIT;


struct mytbf_st {
    int cps;
    int burst;
    int token;
    int pos;
    pthread_mutex_t mut;
    pthread_cond_t cond;
};

static void *thr_alrm(void *p) {
    while(1) {
        for(int i = 0; i < MYTBF_MAX; ++i) {
            pthread_mutex_lock(&mut_job);
            if(job[i] != NULL) {
                pthread_mutex_lock(&job[i]->mut);
                job[i]->token += job[i]->cps;
                if(job[i]->token > job[i]->burst) {
                    job[i]->token = job[i]->burst;
                }
                pthread_cond_broadcast(&job[i]->cond);
                pthread_mutex_unlock(&job[i]->mut);
            }
            pthread_mutex_unlock(&mut_job);
        }
        usleep(onesec);
    }
}

static void module_unload() {
    pthread_cancel(tid_alrm);
    pthread_join(tid_alrm, NULL);
    for(int i = 0; i < MYTBF_MAX; ++i) {
        if(job[i] != NULL) {
            mytbf_destroy(job[i]);
        }
    }
    pthread_mutex_destroy(&mut_job);
}

static void module_load() {
    int err;
    err = pthread_create(&tid_alrm, NULL, thr_alrm, NULL);    
    if(err) {
        fprintf(stderr, "pthread_create(): %s\n", strerror(err));
        exit(1);
    }
    atexit(module_unload);
}

//从名字是体现出来，改函数没有加锁，但是调用这个函数需要加锁
static int get_free_pos_unlocked() {
    for(int i = 0; i < MYTBF_MAX; ++i) {
        if(job[i] == NULL) 
            return i;
    }
    return -1;
}

mytbf_t *mytbf_init(int cps, int burst)
{
    struct mytbf_st *me;

    pthread_once(&init_once, module_load);

    me = malloc(sizeof(*me));
    if(me == NULL) 
        return NULL;
    me->token = 0;
    me->cps = cps;
    me->burst = burst;
    pthread_mutex_init(&me->mut, NULL);
    pthread_cond_init(&me->cond, NULL);

    pthread_mutex_lock(&mut_job);
    int pos = get_free_pos_unlocked();
    if(pos < 0) {
        pthread_mutex_unlock(&mut_job);
        free(me);
        return NULL;
    }
    me->pos = pos;
    job[pos] = me;
    pthread_mutex_unlock(&mut_job);
    return me;
}

static int min(int a, int b) {
    return a < b ? a : b;
}

int mytbf_fetchtoken(mytbf_t *ptr, int size)
{
    struct mytbf_st *me = ptr;
    if(size <= 0) {
        return -EINVAL;
    } 
    pthread_mutex_lock(&me->mut);
    while(me->token <= 0) {
        //功能相当于下面三句话
        pthread_cond_wait(&me->cond, &me->mut);
        // pthread_mutex_unlock(&me->mut);
        // sched_yield();
        // pthread_mutex_lock(&me->mut);
    }
    int n = min(me->token, size);
    me->token -= n;
    pthread_mutex_unlock(&me->mut);
    return n;
}

int mytbf_returntoken(mytbf_t *ptr, int size)
{
    struct mytbf_st *me = ptr;
    if(size <= 0) {
        return -EINVAL;
    }
    pthread_mutex_lock(&me->mut);
    me->token += size;
    if(me->token > me->burst) {
        me->token = me->burst;
    }
    pthread_cond_signal(&me->cond);
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
    pthread_cond_destroy(&me->cond);
    free(ptr);
    return 0;
}