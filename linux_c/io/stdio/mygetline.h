#ifndef MY_GETLINE
#define MY_GETLINE
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int mygetline(char **lineptr, size_t *n, FILE *stream);

void mygetline_free(char ** lineptr);

#endif