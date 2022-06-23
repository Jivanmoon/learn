#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define CPS 10
#define BUFSIZE CPS
#define BURST 100

//当把变量声明为sig_atomic_t类型会保证该变量在使用或赋值时， 无论是在32位还是64位的机器上都能保证操作是原子的， 它会根据机器的类型自动适应。
static volatile sig_atomic_t token = 0;

static void alarm_handler(int sig)
{   
    ++token;
    if(token > BURST) 
        token = BURST;
    alarm(1);
}

int main(int argc, char **argv)
{
    int sfd, dfd = 1;
    char buf[BUFSIZE];
    int len, ret, pos;

    if (argc < 2)
    {
        fprintf(stderr, "usage...");
        exit(1);
    }
    signal(SIGALRM, alarm_handler);
    alarm(1);
    do
    {
        sfd = open(argv[1], O_RDONLY);
        if (sfd < 0)
        {
            if (errno != EINTR)
            {
                perror("open()");
                exit(1);
            }
        }
    } while (sfd < 0);

    while (1)
    {
        while (token <= 0)
            pause();
        //这里需要确保--token操作是原子的
        --token;
        while ((len = read(sfd, buf, BUFSIZE)) < 0)
        {
            if (errno == EINTR)
                continue;
            perror("read()");
            break;
        }
        if (len == 0) break;

        pos = 0;
        while (len > 0)
        {
            do
            {
                ret = write(dfd, buf + pos, len);
                if (ret < 0)
                {
                    if (errno != EINTR)
                    {
                        perror("write()");
                        exit(1);
                    }
                }
            } while (ret < 0);
            pos += ret;
            len -= ret;
        }
    }
    close(dfd);
    close(sfd);
    exit(0);
}