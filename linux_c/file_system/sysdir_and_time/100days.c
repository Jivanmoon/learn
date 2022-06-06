#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TIMESTRSIZE 1024

int main() {
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];

    stamp = time(NULL);
    tm = localtime(&stamp);
    strftime(timestr, TIMESTRSIZE, "Now:%Y-%m-%d", tm);
    puts(timestr);

    tm->tm_mday += 100;
    //mktime会检查当前的时间参数是否正确，如果有不合适的地方，自动调整合适
    mktime(tm);
    strftime(timestr, TIMESTRSIZE, "after 100 days:%Y-%m-%d", tm);
    puts(timestr);
    exit(0);
}