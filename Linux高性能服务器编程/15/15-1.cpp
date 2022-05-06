//filename: processpool.h
#ifndef PROCESSPOOL_H
#define PROCESSPOOL_H

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/stat.h>

//a class to describe a process, m_pid is process's pid, m_pipefd is the communication pipe of parent process and child process
class process {
public:
    process() : m_pid(-1) {}

public:
    pid_t m_pid;
    int m_pipefd[2];
}

//process pool class, defined as a template class to code reuse. its template parameter is a class that handles logical tasks
template<typename T>
class processpool {
private:
    //将构造函数定义为私有的，因此我们只能通过后面的create静态函数来创建processpool实例
    processpool(int listenfd, int process_number = 8);
public:
    //单例模式，以保证程序最多只创建一个processpool实例，这是程序正确处理信号的必要条件
    static processpool<T> *create(int listenfd, int process_number = 8) {
        if(!m_instance) {
            m_instance = new processpool<T>(listenfd, process_number);
        }
        return m_instance;
    }
    
    ~processpool() {
        delete[] m_sub_process;
    }

    //启动线程池
    void run();

private:
    void setup_sig_pipe();
    void run_parent();
    void run_child();

private:
    //maximum number of processes allowed in the process pool
    static const int MAX_PROCESS_NUMBER = 16;
    //maximum number of clients that each subprocess can handle
    static const int USER_PER_PROCESS = 65536;
    //maximum number of events that epoll can handle
    static const int MAX_EVENT_NUMBER = 10000;
    //number of process in process pool
    int m_process_number;
    //sequence number of subprocess in pool, begin at 0
    int m_idx;
    //every process has a epoll kernal event table, use m_epollfd identification
    int m_epollfd;
    //monitor socket
    int m_listenfd;
    //subprocess through m_stop determines whether to stop the operation
    int m_stop;
    //save all subprocess's information
    process *m_sub_process;
    //process pool static instance
    static processpool<T> *m_instance;
};
template<typename T>
processpool<T> *processpool<T>::m_instance = NULL;

//用于处理信号的管道，以实现统一事件源，后面称之为信号管道
static int sig_pipefd[2];

static int setnonblocking(int fd) {
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

static void addfd(int epollfd, int fd) {
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

//从epollfd标识的epoll内核时间表中删除fd上的所有注册时间
static void removefd(int epollfd, int fd) {
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, 0);
    close(fd);
}

static void sig_handler(int sig) {
    int save_errno = errno;
    int msg = sig;
    send(sig_pipefd[1], (char *)&msg, 1, 0);
    errno = save_errno;
}

static void addsig(int sig, void(*handler)(int), bool restart = true) {
    struct sigaction sa;
    memset(&sa, '\0', sizeof(sa));
    sa.sa_hander = handler;
    if(restart) {
        sa.sa_flags |= SA_RESTART;
    }
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig, &sa, NULL) != -1);
}



#endif