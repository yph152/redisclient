#ifndef MYLOG_H_
#define MYLOG_H_


#include <stdio.h>

#define Infof(pszContent,...)    INFOF(__FILE__,__FUNCTION__,__LINE__,pszContent,##__VA_ARGS__)
#define Warnf(pszContent,...)    WARNF(__FILE__,__FUNCTION__,__LINE__,pszContent,##__VA_ARGS__)
#define Errorf(pszContent,...)   ERRORF(__FILE__,__FUNCTION__,__LINE__,pszContent,##__VA_ARGS__)
#define Debugf(pszContent,...)   DEBUGF(__FILE__,__FUNCTION__,__LINE__,pszContent,##__VA_ARGS__)
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
        void ResetLogLevel(LogLevel newloglevel);
        void INFOF(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *format,...);
        void WARNF(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *format,...);
        void ERRORF(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *format,...);
        void DEBUGF(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *format,...);
    private:
        void writeLogFile(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *pszContent);
        void getTime(char *szTimeStr);
    private:
        LogLevel loglevel_;
        FILE *fp_;
};

#endif
