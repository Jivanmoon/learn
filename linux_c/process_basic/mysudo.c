#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char **argv) {
    if(argc < 3) {
        fprintf(stderr, "...\n");
        exit(1);
    }
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork()");
        exit(1);
    }
    if(pid == 0) {
        //其实并能随便把自己的权限设置为其他权限
        setuid(atoi(argv[1]));
        execvp(argv[2], argv + 2);
        perror("execvp()");
        exit(1);
    }
    wait(NULL);
    exit(0);
}