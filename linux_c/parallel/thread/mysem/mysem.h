#ifndef MYSEM_H
#define MYSEM_H
typedef void mysem_t;
mysem_t *mysem_init(int initval);

int mysem_add(mysem_t *, int);

int mysem_sub(mysem_t *, int);

int mysem_destroy(mysem_t *);

#endif