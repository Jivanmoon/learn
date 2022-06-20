#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

static volatile int loop = 1;

static void alarm_handler(int sig) {
    loop = 0;
}

int main() {
    int64_t count = 0;
    alarm(5);
    signal(SIGALRM, alarm_handler);
    while(loop) ++count;
    printf("%ld\n", count);
    exit(0);
}