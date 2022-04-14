#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<assert.h>
#include<sys/epoll.h>
#include<pthread.h>

#define MAX_EVENT_BUMBER 1024
#define BUFFER_SIZE 1024

struct fds {
    int epollfd;
    int sockfd;
};

int setnonblocking(int fd) {
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

//将fd上的EPOLLIN和EPOLLET事件注册到epollfd指示的epoll内核事件表表中，参数oneshot指定是否注册fd上EPOLLONESHOT事件
void addfd(int epollfd, int fd, bool oneshot) {
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    if(oneshot) {
        event.events |= EPOLLONESHOT;
    }
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

//充值fd上的事件，这样操作之后，尽管fd上的EPOLLONESHOT事件被注册，但是操作系统仍会触发fd上的EPOLLIN事件，且只触发一次
void reset_oneshot(int epollfd, int fd) {
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLONESHOT;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event);
}

//工作线程
void* worker(void* arg) {
    int sockfd = ((fds*)arg)->sockfd;
    int epollfd = ((fds*)arg)->epollfd;
    printf("start new thread to recive data on fd: %d\n", sockfd);
    char buf[BUFFER_SIZE];
    memset(buf, '\0', BUFFER_SIZE);
    //循环读取sockfd上的数据，知道遇到EAGAIN错误
    while(1) {
        int ret = recv(sockfd, buf, BUFFER_SIZE - 1, 0);
        if(ret == 0) {
            close(sockfd);
            printf("foreiner closed the connection\n");
            break;
        }
        else if(ret < 0) {
            if(errno == EAGAIN) {
                reset_oneshot(epollfd, sockfd);
                printf("read later\n");
                break;
            }
        }
        else {
            printf("get content: %s\n", buf);
            //休眠5s，模拟数据处理过程
            sleep(5);
        }
    }
    printf("end thread reciving data on fd: %d\n", sockfd);
}

int main(int argc, char* argv[]) {
    if (argc <= 2)
    {
        printf("usage: %s ip_address port_number\n", basename(argv[0]));
        return -1;
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);


    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);
    int ret = bind(listenfd, (sockaddr *)&address, sizeof(address));
    assert(ret != -1);
    ret = listen(listenfd, 5);
    assert(ret != -1);

    epoll_event events[MAX_EVENT_BUMBER];
    int epollfd = epoll_create(5);
    assert(epollfd != -1);
    //注意，监听socket listenfd上是不能注册EPOLLONESHOT事件的，否则应用程序只能处理一个连接，因为后续的客户连接请求将不在触发listenfd上的EPOLLIN事件
    addfd(epollfd, listenfd, false);

    while(1) {
        int ret = epoll_wait(epollfd, events, MAX_EVENT_BUMBER, -1);
        if(ret < 0) {
            printf("epoll failure\n");
            break;
        }

        for(int i = 0; i < ret; ++i) {
            int sockfd = events[i].data.fd;
            if(sockfd == listenfd) {
                sockaddr_in client;
                socklen_t client_addrlen = sizeof(client);
                int connfd = accept(listenfd, (sockaddr*)&client, &client_addrlen);
                //对每个非监听文件描述符都注册EPOLLONESHOT事件
                addfd(epollfd, connfd, true);
            }
            else if(events[i].events & EPOLLIN) {
                pthread_t thread;
                fds fds_for_new_worker;
                fds_for_new_worker.epollfd = epollfd;
                fds_for_new_worker.sockfd = sockfd;
                pthread_create(&thread, NULL, worker, (void*)&fds_for_new_worker);
            }
            else {
                printf("something else happened\n");
            }
        }
    }
    close(listenfd);
    return 0;
}