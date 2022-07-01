#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

static void *func(void *p) {
    puts("thread is working");
    //return NULL;
    pthread_exit(NULL);
}

int main() {
    puts("begin");

    pthread_t tid;
    int err = pthread_create(&tid, NULL, func, NULL);
    if(err) {
        fprintf(stderr, "pthread_create():%s", strerror(err));
    }
    pthread_join(tid, NULL);
    puts("end");
    exit(0);
}