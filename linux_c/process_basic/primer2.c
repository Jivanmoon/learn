#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

#define LEFT 30000000
#define RIGHT 30000200

int main()
{
    int i;
    for (i = LEFT; i <= RIGHT; ++i)
    {

        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork()");
            exit(1);
        }
        else if (pid == 0)
        {
            int mark = 1;
            for (int j = 2; j < i / 2; ++j)
            {
                if (i % j == 0)
                {
                    mark = 0;
                    break;
                }
            }
            if (mark)
                printf("%d is a primer\n", i);
            exit(0);
        }
    }
    int st;
    for(i = LEFT; i <= RIGHT; ++i) {
        wait(&st);
    }
    exit(0);
}