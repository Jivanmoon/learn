#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

#define PATHSIZE 1024

static int path_noloop(const char *path) {
    //去除隐藏目录.和..因为会造成递归死循环
    char *pos = strrchr(path, '/');
    if(pos == NULL) 
        exit(1);
    if(strcmp(pos + 1, ".") == 0 || strcmp(pos + 1, "..") == 0) {
        return 0;
    }
    return 1;
} 

static int64_t mydu2(const char *path) {
    //puts(path);
    //path为非目录文件
    static struct stat statres;

    if(lstat(path, &statres) < 0) {
        perror("lstat()");
        exit(1);
    }
    if(!S_ISDIR(statres.st_mode)) {
        return statres.st_blocks;
    }
    //path为目录文件
    else {
        int64_t sum = statres.st_blocks;
        char nextpath[PATHSIZE];
        DIR *dp;
        strncpy(nextpath, path, PATHSIZE);
        strncat(nextpath, "/", PATHSIZE);
        dp = opendir(nextpath);
        if(dp == NULL) {
            perror("opendir()");
            exit(1);
        }
        struct dirent *cur;
        while((cur = readdir(dp)) != NULL) {
            strncat(nextpath, cur->d_name, PATHSIZE);
            if(path_noloop(nextpath)) {
                sum += mydu2(nextpath);
            }    
            strncpy(nextpath, path, PATHSIZE);
            strncat(nextpath, "/", PATHSIZE);
        }
        return sum;
    }
}

int main(int argc, char **argv) {
    if(argc < 2) {
        fprintf(stderr, "Usage....\n");
        exit(1);
    }
    for(int i = 1; i < argc; ++i) {
        printf("%ld\n", mydu2(argv[i]) / 2);
    }
    exit(0);
}