#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main() {

    alarm(10);
    alarm(5);
    //while(1);
    pause();
    exit(0);
}