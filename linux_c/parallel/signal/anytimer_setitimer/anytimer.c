#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>
#include "anytimer.h"

static struct myat_st *job[JOB_MAX];
static int inited = 0;
static void (*alarm_handler_save)(int); 

struct myat_st {
    int sec;
    at_jobfunc_t *jobp;
    void *arg;
    /**
     * flag = 1 任务正常运行
     *      = 2 任务被取消
     *      = 3 任务已完成，等待被释放
     */ 
    int flag;
};

int get_free_pos() {
    for(int i = 0; i < JOB_MAX; ++i) {
        if(job[i] == NULL) 
            return i;
    }
    return -1;
}

static void alarm_handler(int sig) {
    for(int i = 0; i < JOB_MAX; ++i) {
        if(job[i] != NULL) {
            job[i]->sec -= 1;
            if(job[i]->sec == 0 && job[i]->flag == 1) {
                job[i]->jobp(job[i]->arg);
                job[i]->flag = 3;
            }
        }
    }
}

static void module_unload() {
    signal(SIGALRM, alarm_handler_save);
    for(int i = 0; i < JOB_MAX; ++i) {
        free(job[i]);
    }
}

static void module_load() {
    alarm_handler_save =  signal(SIGALRM, alarm_handler);
    struct itimerval itv;
    itv.it_interval.tv_sec = 1;
    itv.it_interval.tv_usec = 0;
    itv.it_value.tv_sec = 1;
    itv.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &itv, NULL);
    atexit(module_unload);
}

int at_addjob(int sec, at_jobfunc_t *jobp, void *arg) {
    if(sec <= 0 || jobp == NULL) {
        return -1;
    }

    struct myat_st *me;

    if(!inited) {
        inited = 1;
        module_load();
    }

    int pos = get_free_pos();
    if(pos < 0) {
        return -2;
    }

    me = malloc(sizeof(*me));
    if(me == NULL) {
        return -3;
    }
    me->sec = sec;
    me->jobp = jobp;
    me->arg = arg;
    me->flag = 1;

    job[pos] = me;

    return pos; 
}

int at_conceljob(int id) {
    if(id < 0 || id >= JOB_MAX) {
        return -1;
    }
    struct myat_st *me = job[id];
    if(me == NULL) {
        return -4;
    }
    if(me->flag == 2) {
        return -3;
    }
    if(me->flag == 3) {
        return -2;
    }
    me->flag = 2;
    return 0;
}

int at_waitjob(int id) {
    if(id < 0 || id >= JOB_MAX) {
        return -1;
    }
    struct myat_st *me = job[id];
    if(me == NULL) {
        return -2;
    }
    while(me->flag == 1) {
        pause();
    }
    job[id] = NULL;
    free(me);
    return 0;
}