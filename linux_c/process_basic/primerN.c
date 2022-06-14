#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define LEFT 30000000
#define RIGHT 30000200
#define N 3

int main()
{
    pid_t pid;
    for (int n = 0; n < N; ++n)
    {
        pid = fork();
        if(pid < 0) {
            //如果创建前两个进程时没有问题，但是创建第三个的时候fork出错，此时应该把前两个子进程释放后父进程再结束
            for(int j = 0; j < n; ++j) 
                wait(NULL);
            perror("fork()");
            exit(1);
        }
        else if (pid == 0)
        {
            for (int i = LEFT + n; i <= RIGHT; i += N)
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
                    printf("[%d]%d is a primer\n", n, i);
            }
            exit(0);
        }
    }
    for(int n = 0; n < N; ++n) 
        wait(NULL);
    exit(0);
}