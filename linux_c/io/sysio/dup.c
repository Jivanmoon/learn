#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<assert.h>

#define FNAME "/tmp/out"

int main() {
    // close(1);
    // int fd;
    // fd = open("/tmp/out", O_CREAT | O_TRUNC | O_RDWR, 0666);
    // assert(fd >= 0);

    // int fd;
    // fd = open("/tmp/out", O_CREAT | O_TRUNC | O_RDWR, 0666);
    // assert(fd >= 0);
    // close(1);
    // dup(fd);

    // close(fd);

    int fd;
    fd = open("/tmp/out", O_CREAT | O_TRUNC | O_RDWR, 0666);
    dup2(fd, 1);
    if(fd != 1)
        close(fd);
/******************************/
    puts("hello!");

    

    exit(0);
}