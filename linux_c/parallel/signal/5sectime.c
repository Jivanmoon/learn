#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<time.h>
#include<sys/types.h>

int main() {
    time_t end;
    int64_t count = 0;
    end = time(NULL) + 5;

    while(time(NULL) <= end) {
        ++count;
    }
    printf("%ld\n", count);

    exit(0);
}