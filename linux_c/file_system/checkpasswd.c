/**
 * 
 * 编译该程序需要使用gcc checkpasswd.c -lcrypt
 * 而不能使用gcc -lcrypt checkpasswd.c 
 * 具体原因我也不太清楚
 * 
 */
#define _XOPEN_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<shadow.h>
#include<string.h>

int main(int argc, char **argv) {
    char *input_pass;
    struct spwd *shadow_line;
    if(argc < 2) {
        fprintf(stderr, "usage..\n");
        exit(1);
    }
    input_pass = getpass("Password:");
    shadow_line = getspnam(argv[1]);

    char *crypted_pass = crypt(input_pass, shadow_line->sp_pwdp);
    if(strcmp(shadow_line->sp_pwdp, crypted_pass) == 0) {
        puts("OK");
    }
    else 
        puts("failure");
    exit(0);
}