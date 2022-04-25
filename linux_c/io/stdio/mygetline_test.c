#include<string.h>
#include"mygetline.h"

int main(int argc, char **argv) {
    
    FILE *fp;
    char *linebuf;
    size_t linesize;

    if(argc < 2) {
        fprintf(stderr, "usage...\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        perror("fopen()");
        exit(1);
    }

    //非常重要，必须赋初值
    linebuf = NULL;
    linesize = 0;
    while(1) {
        if(mygetline(&linebuf, &linesize, fp) < 0) break;
        printf("%ld\n", strlen(linebuf));
        printf("%ld\n", linesize);
    }

    mygetline_free(&linebuf);
    fclose(fp);
    exit(0);
}