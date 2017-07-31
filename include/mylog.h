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
        void MyLogInit(LogLevel loglevel,const char *filename);
        void Infof(const char *format);
        void Warnf(const char *format);
        void Errorf(const char *format);
        void Debugf(const char *format);
    private:
        void writeLogFile(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *pszContent);
        void getTime(char *szTimeStr);
    private:
        LogLevel loglevel_;
        FILE *fp_;
};

#endif
