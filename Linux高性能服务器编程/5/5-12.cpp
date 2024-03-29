#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<unistd.h>
#include<assert.h>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    char *host = argv[1];

    //获取目标主机地址信息
    struct hostent *hostinfo = gethostbyname(host);
    assert(hostinfo);

    //获取daytime服务信息
    struct servent *servinfo = getservbyname("daytime", "tcp");
    assert(servinfo);
    printf("daytime port is %d\n", ntohs(servinfo->s_port));

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = servinfo->s_port;

    //因为h_addr_list本身就是使用网络字节序的地址列表，所以使用其中的ip地址时，无需对目标ip地址转换字节序
    address.sin_addr = *(struct in_addr *)*hostinfo->h_addr_list;
    char str[INET_ADDRSTRLEN];
    const char *ip = inet_ntop(AF_INET, &address.sin_addr, str, INET_ADDRSTRLEN);
    printf("the host ip is: %s\n", ip);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int result = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
    assert(result != -1);

    char buffer[128];
    result = read(sockfd, buffer, sizeof(buffer));
    assert(result > 0);
    buffer[result] = '\0';
    printf("the day time is: %s\n", buffer);
    close(sockfd);
    return 0;
}