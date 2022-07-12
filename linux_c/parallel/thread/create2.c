#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

void *func(void *p) {
    while(1) {
        pause();
    }
}

int main() {
    int i;
    pthread_t tid;
    for(i = 0; ; ++i) {
        int err = pthread_create(&tid, NULL, func, NULL);
        if(err) {
            fprintf(stderr, "pthread_create(): %s %d\n", strerror(err), i);
            exit(1);
        }
    }
    exit(0);
}