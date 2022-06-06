#include<stdio.h>
#include<stdlib.h>
#include<glob.h>
#include<string.h>
#define PAT "/etc/*"

#if 0
static int errfunc_(const char *errpath, int errno) {
    puts(errpath);
    fprintf(stderr, "ERROR MSG:%s\n", strerror(errno));
    return 0;
}
#endif


int main() {
    glob_t globres;
    int err = glob(PAT, 0, NULL, &globres);
    if(err) {
        printf("Error code = %d\n", err);
        exit(1);
    }
    for(int i = 0; i < globres.gl_pathc; ++i) {
        puts(globres.gl_pathv[i]);
    }
    globfree(&globres);
    exit(0);
}