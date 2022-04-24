#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    int count = 0;

    if(argc < 2) {
        fprintf(stderr, "usage:...");
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        perror("fopen()");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    printf("%ld\n", ftell(fp));

    fclose(fp);

    exit(0);
}