#ifndef MYCLIENT_H_
#define MYCLIENT_H_


#define REDIS_REPLY_STRING   1
#define REDIS_REPLY_ARRAY    2
#define REDIS_REPLY_INTEGER  3
#define REDIS_REPLY_NIL      4
#define REDIS_REPLY_STATUS   5
#define REDIS_REPLY_ERROR    6

typedef struct redisReply {
    int type;
    long long integet;
    int len;
    char *str;
    size_t elements;
    struct redisReply **element;
};

class RedisCli{
    public:
        RedisCli();
        ~RedisCli();
    private:
        //将参数转化为redis协议
        char *getCmd(char **str);
        void *delReply(char *reply);
        //处理状态响应
        void *dealStatusReply(char *reply);
        //处理主体响应
        void *dealBulkReply(char *reply);

    public:
        Connect(const char *ip,int port);
        SendCommand(const char *command);
    private:
        int err;
        char errstr[128];
        int sockfd;
        int flag;
        char *obuf;
};

#endif
