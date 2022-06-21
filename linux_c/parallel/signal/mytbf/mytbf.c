#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<signal.h>
#include<unistd.h>
#include "mytbf.h"

static struct mytbf_st *job[MYTBF_MAX];

static int inited = 0;

static void (*alarm_handler_save)(int); 

struct mytbf_st {
    int cps;
    int burst;
    int token;
    int pos;
};

static void alarm_handler(int s) {
    alarm(1);
    for(int i = 0; i < MYTBF_MAX; ++i) {
        if(job[i] != NULL) {
            job[i]->token += job[i]->cps;
            if(job[i]->token > job[i]->burst) {
                job[i]->token = job[i]->burst;
            }
        }
    }
}

static void module_unload() {
    signal(SIGALRM, alarm_handler_save);
    alarm(0);
    for(int i = 0; i < MYTBF_MAX; ++i) {
        free(job[i]);
    }
}

static void module_load() {
    alarm_handler_save =  signal(SIGALRM, alarm_handler);
    alarm(1);
    
    atexit(module_unload);
}


static int get_free_pos() {
    for(int i = 0; i < MYTBF_MAX; ++i) {
        if(job[i] == NULL) 
            return i;
    }
    return -1;
}

mytbf_t *mytbf_init(int cps, int burst)
{
    struct mytbf_st *me;

    if(!inited) {
        module_load();
        inited = 1;
    }

    int pos = get_free_pos();
    if(pos < 0) {
        return NULL;
    }
    me = malloc(sizeof(*me));
    if(me == NULL) 
        return NULL;
    me->token = 0;
    me->cps = cps;
    me->burst = burst;
    me->pos = pos;
    job[pos] = me;
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
    while(me->token <= 0) 
        pause();
    int n = min(me->token, size);
    me->token -= n;
    return n;
}

int mytbf_returntoken(mytbf_t *ptr, int size)
{
    struct mytbf_st *me = ptr;
    if(size <= 0) {
        return -EINVAL;
    }
    me->token += size;
    if(me->token > me->burst) {
        me->token = me->burst;
    }
    return size;
}

int mytbf_destory(mytbf_t *ptr)
{
    struct mytbf_st *me = ptr;
    job[me->pos] = NULL;
    free(me);
    return 0;
}