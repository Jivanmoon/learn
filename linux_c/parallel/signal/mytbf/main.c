#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include<string.h>
#include "mytbf.h"

#define CPS 10
#define BUFSIZE 1024
#define BURST 100

static volatile int token = 0;

int main(int argc, char **argv)
{
    int sfd, dfd = 1;
    char buf[BUFSIZE];
    int len, ret, pos;
    mytbf_t *tbf;
    int size;

    if (argc < 2)
    {
        fprintf(stderr, "usage...");
        exit(1);
    }

    tbf = mytbf_init(CPS, BURST);
    if(tbf == NULL) {
        fprintf(stderr, "mytbf_init() failed!\n");
        exit(1);
    }

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
        size = mytbf_fetchtoken(tbf, 1024);
        if(size < 0) {
            fprintf(stderr, "mytbf_fetchtoken(): %s\n", strerror(-size));
        }
        while ((len = read(sfd, buf, size)) < 0)
        {
            if (errno == EINTR)
                continue;
            perror("read()");
            break;
        }
        if (len == 0) break;

        if(size - len > 0) {
            mytbf_returntoken(tbf, size - len);
        }

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
    close(sfd);
    mytbf_destory(tbf);
    exit(0);
}