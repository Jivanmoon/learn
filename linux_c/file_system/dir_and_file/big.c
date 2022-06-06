#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv) {

    if(argc < 2) {
        fprintf(stderr, "...");
        exit(1);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd < 0) {
        perror("open()");
        exit(1);
    }

    lseek(fd, 5LL * 1024LL * 1024LL * 1024LL, SEEK_SET);
    //if error
    write(fd, "", 1);

    close(fd);
    exit(0);
}