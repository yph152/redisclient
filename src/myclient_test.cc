#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>

int main(){
    const char *ip = "127.0.0.1";
    int port = 6379;
    int sockfd = socket(PF_INET,SOCK_STREAM,0);
    assert( sockfd >= 0);

    struct sockaddr_in address;
    bzero(&address,sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&address.sin_addr);

    address.sin_port = htons(port);

    int ret = connect(sockfd,(struct sockaddr*)&address,sizeof(address) );

    assert( ret >=  0);

    const char *data = "*1\r\n$4\r\ninfo\r\n";
    send(sockfd,data,strlen(data),0);

    char buf[2048] = {};

    ret = recv(sockfd,buf,2047,0);
    printf("recv\n%s",buf);
    close(sockfd);



}
