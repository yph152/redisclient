#include "../include/myclient.h"
#include <string>
#include <vector>
#include <sstream>

RedisCli::Conn(){

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
