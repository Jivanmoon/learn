#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>


static void cleanup_func(void *p) {
    puts(p);
}

static void *func(void *p) {
    puts("thread is working");

    pthread_cleanup_push(cleanup_func, "cleanup1");
    pthread_cleanup_push(cleanup_func, "cleanup2");
    pthread_cleanup_push(cleanup_func, "cleanup3");

    puts("push over");

    //pthread_exit(NULL);

    pthread_cleanup_pop(1);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit(NULL);
}


int main() {

    puts("begin");

    pthread_t tid;
    int err = pthread_create(&tid, NULL, func, NULL);
    if(err) {
        fprintf(stderr, "pthread_creare():%s\n", strerror(err));
    }

    pthread_join(tid, NULL);
    puts("end");
    exit(0);
}