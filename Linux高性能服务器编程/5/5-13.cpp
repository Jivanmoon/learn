#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    char *host = argv[1];

    struct addrinfo hints;
    struct addrinfo *res;

    bzero(&hints, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;
    getaddrinfo(host, "daytime", &hints, &res);
    freeaddrinfo(res);
    return 0;
}