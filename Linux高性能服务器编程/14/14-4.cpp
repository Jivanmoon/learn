#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

pthread_mutex_t mutex;

//子线程运行的函数，它首先获得互斥锁mutex，然后暂停5s，再释放该互斥锁
void *another(void *arg)
{
    printf("in child thread, lock the mutex\n");
    pthread_mutex_lock(&mutex);
    sleep(1);
    pthread_mutex_unlock(&mutex);
    printf("in child thread, unlock the mutex\n");
}

void prepare(void)
{
    printf("in prepare(), lock the mutex\n");
    pthread_mutex_lock(&mutex);
}

void parent(void)
{
    printf("in parent(), unlock the mutex\n");
    pthread_mutex_unlock(&mutex);
}

void child(void)
{
    printf("in child(), unlock the mutex\n");
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t id;
    pthread_create(&id, NULL, another, NULL);
    // the main thread in parent process sleep 1s, to ensure before implememt fork, the child thread already ran and got the mutex
    sleep(1);
    pthread_atfork(prepare, parent, child);
    int pid = fork();
    if (pid < 0) {
        pthread_join(id, NULL);
        pthread_mutex_destroy(&mutex);
        return 1;
    }
    else if (pid == 0) {
        printf("I am in the child, want to get the lock\n");
        // the child process inherit the mutex status from parent process, the mutex is locked because the parent process's thread implememt pthread_mutex_lock(), thus, the lock operation below will always blokced, although, it should not be locked in logic
        pthread_mutex_lock(&mutex);
        printf("I can not run to here, oop...\n");
        pthread_mutex_unlock(&mutex);
        exit(0);
    }
    else {
        wait(NULL);
    }
    pthread_join(id, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}