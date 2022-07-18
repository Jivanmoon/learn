#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include "anytimer.h"

static struct myat_st *job[JOB_MAX];
static pthread_mutex_t job_mut = PTHREAD_MUTEX_INITIALIZER;
static pthread_once_t init_once = PTHREAD_ONCE_INIT;
static pthread_t tid;
static unsigned int onesec = 1e6;
enum {
    RUNNING = 1,
    CANCELED,
    SUCCEED
};

struct myat_st {
    int sec;
    at_jobfunc_t *jobp;
    void *arg;
    int flag;
    pthread_mutex_t mut;
    pthread_cond_t cond;
};

int get_free_pos_unlocked() {
    for(int i = 0; i < JOB_MAX; ++i) {
        if(job[i] == NULL) 
            return i;
    }
    return -1;
}

static void *thr_alarm(void *p) {
    while(1) {
        for(int i = 0; i < JOB_MAX; ++i) {
            pthread_mutex_lock(&job_mut);
            if(job[i] != NULL) {
                pthread_mutex_lock(&job[i]->mut);
                job[i]->sec -= 1;
                if(job[i]->sec == 0 && job[i]->flag == RUNNING) {
                    job[i]->jobp(job[i]->arg);
                    job[i]->flag = SUCCEED;
                    pthread_cond_broadcast(&job[i]->cond);
                }
                pthread_mutex_unlock(&job[i]->mut);
            }
            pthread_mutex_unlock(&job_mut);
        }
        sleep(1);
    }
}

static void module_unload() {
    pthread_cancel(tid);
    pthread_join(tid, NULL);
    for(int i = 0; i < JOB_MAX; ++i) {
        if(job[i]) {
            at_conceljob(i);
            at_waitjob(i);
        }
    }
    pthread_mutex_destroy(&job_mut);
}

static void module_load() {
    printf("module_load\n");
    int err;
    err = pthread_create(&tid, NULL, thr_alarm, NULL);
    if(err) {
        fprintf(stderr, "pthread_create(): %s\n", strerror(err));
        exit(1);
    }
    atexit(module_unload);
}

int at_addjob(int sec, at_jobfunc_t *jobp, void *arg) {
    if(sec <= 0 || jobp == NULL) {
        return -1;
    }
    pthread_once(&init_once, module_load);

    struct myat_st *me;
    me = malloc(sizeof(*me));
    if(me == NULL) {
        return -3;
    }
    me->sec = sec;
    me->jobp = jobp;
    me->arg = arg;
    me->flag = RUNNING;
    pthread_mutex_init(&me->mut, NULL);
    pthread_cond_init(&me->cond, NULL);

    pthread_mutex_lock(&job_mut);
    int pos = get_free_pos_unlocked();
    if(pos < 0) {
        pthread_mutex_unlock(&job_mut);
        return -2;
    }
    job[pos] = me;
    pthread_mutex_unlock(&job_mut);

    return pos; 
}

int at_conceljob(int id) {
    if(id < 0 || id >= JOB_MAX) {
        return -1;
    }
    pthread_mutex_lock(&job_mut);
    struct myat_st *me = job[id];
    pthread_mutex_unlock(&job_mut);
    pthread_mutex_lock(&me->mut);
    if(me == NULL) {
        pthread_mutex_unlock(&me->mut);
        return -3;
    }
    if(me->flag == CANCELED) {
        pthread_mutex_unlock(&me->mut);
        return 0;
    }
    if(me->flag == SUCCEED) {
        pthread_mutex_unlock(&me->mut);
        return -2;
    }
    me->flag = CANCELED;
    pthread_mutex_unlock(&me->mut);
    return 0;
}

int at_waitjob(int id) {
    if(id < 0 || id >= JOB_MAX) {
        return -1;
    }

    pthread_mutex_lock(&job_mut);
    struct myat_st *me = job[id];
    if(me == NULL) {
        pthread_mutex_unlock(&job_mut);
        return -2;
    }
    pthread_mutex_lock(&me->mut);
    while(me->flag == RUNNING) {
        pthread_cond_wait(&me->cond, &me->mut);
    }
    job[id] = NULL;
    pthread_mutex_unlock(&job_mut);
    pthread_mutex_destroy(&me->mut);
    pthread_cond_destroy(&me->cond);
    free(me);
    return 0;
}