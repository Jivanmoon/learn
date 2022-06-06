#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#define PAT "/etc/"

int main() {

    DIR *dp = opendir(PAT);
    if(dp == NULL) {
        perror("opendir()");
        exit(1);
    }
    struct dirent *cur;
    while((cur = readdir(dp)) != NULL) {
        puts(cur->d_name);
    }
    
    closedir(dp);

    exit(0);
}