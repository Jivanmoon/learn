#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {
#pragma omp parallel 
{
    printf("[%d]Hello\n", omp_get_thread_num());
    printf("[%d]World\n", omp_get_thread_num());
}
    exit(0);
}