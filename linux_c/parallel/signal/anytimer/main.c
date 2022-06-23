#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "anytimer.h"

static void f2(void *p) {
    printf("f2(): %s\n", p);
}

static void f1(void *p) {
    printf("f1(): %s\n", p);
}


int main() {
    puts("begin!");
    /**
     * 5秒钟后调用f1，传"aaa"
     * 2秒钟后调用f2，传"bbb"
     * 7秒钟后调用f1，传"ccc"
     */  
    int job1 = at_addjob(5, f1, "aaa");
    if(job1 < 0) {
        fprintf(stderr, "at_addjob():%s\n", strerror(-job1));
    }
    int job2 = at_addjob(2, f2, "bbb");
    if(job2 < 0) {
        fprintf(stderr, "at_addjob():%s\n", strerror(-job1));
    }
    int job3 = at_addjob(7, f1, "ccc");
    if(job3 < 0) {
        fprintf(stderr, "at_addjob():%s\n", strerror(-job1));
    }
    puts("end!");
    while(1) {
        write(1, ".", 1);
        sleep(1);
    }
    exit(0);
}