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

