#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main() {
    FILE *fp;
    fp = fopen("tmp", "r");
    if(fp == NULL) {
        // fprintf(stderr, "fopen() failed! errno = %d\n", errno);
        
        //Print a message describing the meaning of the value of errno.
        // perror("fopen()");

        fprintf(stderr, "fopen():%s\n", strerror(errno));
        exit(1);
    }
    puts("OK!");

    fclose(fp);
    exit(0);
}