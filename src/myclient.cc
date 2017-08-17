#include "../include/myclient.h"
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
const char *RedisCli::getCmd(char** args){
    int len =  3;
    int strlen = 0;
    char str[4] = {};
    itoa(3, str, 10);
    
    for(int i=0;i<len;i++){
        strlen = strlen(args[i]);
        cmdString = "$" + itoa(strlen) + "\r\n" + args[i] + "\r\n";
    }
    return cmdString;
}
char *RedisCli::dealReply(char *reply){
    char responType = reply[0];

    switch (responType){
        case '+': return dealStatusReply(reply);
        case '$': return dealBulkReply(reply);
        default: return "proto wrong!"
    }
}
//处理状态响应
char *RedisCli::dealStatusReply(char *reply){
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
char *RedisCli::dealBulkReply(char *reply){
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
char *RedisCli::SendCommand(char *command,...){

}
char **RedisCli::kong(const char *str){
	char command[3][56] = {};
	char buf[56] = {};
	int len = strlen(str);
	int j = 0;
	int i = 0;
	int k = len;
	int s = 0;
	int n = 0;
	while(str[i] == ' '){
		i++;
	}
	while(str[k] == ' '){
		k--;
	}
	for(;i<=k;){
		while(str[i] != ' '){
			buf[s] = str[i];
			s++;
			i++;
		}
		buf[s] = '\0';
		strcpy(command[n],buf);
		memset(buf,'\0',56);
		n++;
		s=0;
		while(str[i] == ' '){
			i++;
		}
	}
	return command;
}
