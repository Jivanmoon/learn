#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<glob.h>

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

static int64_t mydu(const char *path) {
    //path为非目录文件
    int64_t sum;
    static struct stat statres;
    static char nextpath[PATHSIZE];
    glob_t globres;

    if(lstat(path, &statres) < 0) {
        perror("lstat()");
        exit(1);
    }
    if(!S_ISDIR(statres.st_mode)) {
        return statres.st_blocks;
    }
    //path为目录文件
    else {
        strncpy(nextpath, path, PATHSIZE);
        strncat(nextpath, "/*", PATHSIZE);
        glob(nextpath, 0, NULL, &globres);


        strncpy(nextpath, path, PATHSIZE);
        strncat(nextpath, "/.*", PATHSIZE);
        if(glob(nextpath, GLOB_APPEND | GLOB_ERR, NULL, &globres) == GLOB_ABORTED) {
            fprintf(stderr, "glob():Permission denied\n");
            exit(1);
        }

        sum = statres.st_blocks;
        for(int i = 0; i < globres.gl_pathc; ++i) {
            if(path_noloop(globres.gl_pathv[i]))
                sum += mydu(globres.gl_pathv[i]);
        }
        globfree(&globres);
        return sum;
    }
}

int main(int argc, char **argv) {
    if(argc < 2) {
        fprintf(stderr, "Usage....\n");
        exit(1);
    }
    for(int i = 1; i < argc; ++i) {
        printf("%ld\n", mydu(argv[i]) / 2);
    }
    exit(0);
}