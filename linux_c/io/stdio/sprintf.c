#include<stdio.h>
#include<stdlib.h>

int main() {
    char buf[1024];
    int year = 2014, month = 5, day = 13;
    snprintf(buf, 1024, "%d-%d-%d", year, month, day);
    puts(buf);
    exit(0);
}