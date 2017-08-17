#include "../include/myclient.h"
#include <string>
#include <vector>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>

RedisCli::Conn(const char *ip,int port){
    sockfd_ = socket(PF_INET,SOCK_STREAM,0);
    assert( sockfd_ >= 0);

    struct sockaddr_in address;
    bzero(&address,sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&address.sin_addr);

    address.sin_port = htons(port);

    int ret = connect(sockfd_,(struct sockaddr*)&address,sizeof(address) );

    assert(ret >= 0);

}
// 将参数转化为redis 请求协议
const char *RedisCli::getCmd(std::vector<std::string> args){
    std::stringstream ss;
    int len =  args.size();
    ss<<len;
    std::string cmdString;
    int strlen = 0;
    cmdString = "*" + ss.str() + "\r\n";
    for(int i=0;i<len;i++){
        strlen = args[i].size();
        ss<<strlen;
        cmdString = "$" + ss.str() + "\r\n" + args[i] + "\r\n";
    }
    return cmdString;
}
char *dealReply(char *reply){
    char responType = reply[0];

    switch (responType){
        case '+': return dealStatusReply(reply);
        case '$': return dealBulkReply(reply);
        default: return "proto wrong!"
    }
}
//处理状态响应
char *dealStatusReply(char *reply){
    char buf[56] = {0};
    for(int i=0;i<56;i++){
        if (reply[i+1] == '\r'){
            break;
        }
        buf[i] = reply[i+1];
    }
    return buf;
}
//处理主体响应
char *dealBulkReply(char *reply){
    char buf[56] = {0};
    for (int i=0;i<56;i++){
        if (reply[i+1] == '\r'){
            break;
        }
        buf[i] = reply[i+1];
    }
    int len = ;
    if (len == -1){
        return NULL
    }
    f
}

