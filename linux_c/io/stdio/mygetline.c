
#include"mygetline.h"


int mygetline(char **lineptr, size_t *n, FILE *stream) {
    if(stream == NULL) {
        errno = 2;
        return -1;
    }
    int ch = 0;
    if(*n == 0) *n = 120;
    if(*lineptr == NULL) *lineptr = malloc(*n);
    int idx = 0;
    while(1) {
        ch = fgetc(stream);
        if(ch == '\n') {
            return idx;
        }
        else if(ch == EOF) {
            return -1;
        }
        else {
            (*lineptr)[idx] = ch;
            ++idx;
            if(idx == *n) {
                *n = (*n) * 2;
                *lineptr = realloc(*lineptr, *n);
                if(*lineptr == NULL) {
                    errno = 12;
                    exit(1);
                }
            }
        }
    }
    return idx;
}

void mygetline_free(char ** lineptr) {
    free(*lineptr);
}
