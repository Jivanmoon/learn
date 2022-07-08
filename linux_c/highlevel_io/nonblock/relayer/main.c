#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<errno.h>
#include <fcntl.h>
#include<string.h>
#include "relayer.h"

#define FILE1 "file1"
#define FILE2 "file2"
#define FILE3 "file3"
#define FILE4 "file4"

#define BUFSIZE 1024

int main() {
    int fd1, fd2, fd3, fd4;
    int job1, job2;
    fd1 = open(FILE1, O_RDWR | O_APPEND);
    if(fd1 < 0) {
        perror("open()");
        exit(1);
    }
    fd2 = open(FILE2, O_RDWR | O_NONBLOCK | O_APPEND);
    if(fd2 < 0) {
        perror("open()");
        exit(1);
    }
    fd3 = open(FILE1, O_RDWR | O_APPEND);
    if(fd3 < 0) {
        perror("open()");
        exit(1);
    }
    fd4 = open(FILE2, O_RDWR | O_NONBLOCK | O_APPEND);
    if(fd4 < 0) {
        perror("open()");
        exit(1);
    }
    
    job1 = rel_add_job(fd1, fd2);
    if(job1 < 0) {
        fprintf(stderr, "rel_add_job(): %s\n", strerror(-job1));
        exit(1);
    }

    job2 = rel_add_job(fd3, fd4);
    if(job2 < 0) {
        fprintf(stderr, "rel_add_job(): %s\n", strerror(-job2));
        exit(1);
    }

    while(1)
        pause();
    close(fd4);
    close(fd3);
    close(fd2);
    close(fd1);
}