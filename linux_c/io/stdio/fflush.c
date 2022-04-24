#include<stdio.h>
#include<stdlib.h>
/**
 * 缓冲区的作用：大多数情况下都是好事，合并系统调用
 * 
 * 行缓冲：换行的时候刷新，满了的时候刷新，强制刷新（标准输出是这样的，因为是终端设备）
 * 
 * 全缓冲：满了的时候刷新，强制刷新（默认，只要不是终端设备）
 * 
 * 无缓冲：如stderr，需要立即输出的内容
 * 
 * 缓冲区模式可以通过setvbuf修改
 * 
 */
int main() {
    int i;

    //加\n和不加结果不一样，因为加\n会使得输出缓冲区刷新
    // printf("before while\n");
    printf("before while\n");
    fflush(stdout);
    while(1) ;
    printf("after while\n");
    exit(0);
}