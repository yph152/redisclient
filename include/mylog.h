#ifndef MYLOG_H_
#define MYLOG_H_


#include <stdio.h>
enum LogLevel {
    INFO = 0,
    WARN = 1,
    ERROR = 2,
    DEBUG = 3,
};
class MyLog {
    public:
        MyLog();
        ~MyLog();
        void MyLogInit(int loglevel,char *filename);
        void Info(char *format,...);
        void Warn(char *format,...);
        void Error(char *format,...);
        void Debug(char *format,...);
    private:
        void writeLogFile(char *pszFileName,char *pszFunctionName,int *codeLine,int *logLevel,char *pszContent);
        void getTime();
    private:
        LogLevel loglevel_;
        FILE *fd_;
};

#endif
