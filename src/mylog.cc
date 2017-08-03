#include "../include/mylog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdarg.h>

MyLog::MyLog(){}
MyLog::~MyLog(){
    if (fp_ != NULL){
        fclose(fp_);
    }
}
void MyLog::MyLogInit(LogLevel loglevel,const char *filename){
    loglevel_ = loglevel;
    if (filename == NULL){
        printf("this filename is null...\n");
        return;
    }
    fp_ = fopen(filename,"ab+");
    if (fp_ == NULL) {
        printf("open file failed...\n");
        return;
    }
    printf("open file success...\n");
}

void MyLog::ResetLogLevel(LogLevel newloglevel){
    loglevel_ = newloglevel;
}

void MyLog::INFOF(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *format,...){
    if (loglevel_ >= 0){
        char Content[1024] = {0};
        va_list ap;
        va_start(ap,format);
        vsnprintf(Content,sizeof(Content)-1,format,ap);
        va_end(ap);
        writeLogFile(pszFileName,pszFunctionName,codeLine,Content);
    }
}

void MyLog::WARNF(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *format,...){
    if (loglevel_ >= 1){
        char Content[1024] = {0};
        va_list ap;
        va_start(ap,format);
        vsnprintf(Content,sizeof(Content)-1,format,ap);
        va_end(ap);
        writeLogFile(pszFileName,pszFunctionName,codeLine,Content);
    }
}
void MyLog::ERRORF(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *format,...){
    if (loglevel_ >= 2){
        char Content[1024] = {0};
        va_list ap;
        va_start(ap,format);
        vsnprintf(Content,sizeof(Content)-1,format,ap);
        va_end(ap);
        writeLogFile(pszFileName,pszFunctionName,codeLine,Content);
    }
}
void MyLog::DEBUGF(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *format,...){
    if (loglevel_ >= 3){
        char Content[1024] = {0};
        va_list ap;
        va_start(ap,format);
        vsnprintf(Content,sizeof(Content)-1,format,ap);
        va_end(ap);
        writeLogFile(pszFileName,pszFunctionName,codeLine,Content);
    }
}
void MyLog::writeLogFile(const char *pszFileName,const char *pszFunctionName,int codeLine,const char *Content){
    char szLogContent[2048] = {0};
    char szLogFormat[1024] = {0};
    char szTimeStr[128] = {0};

    if (pszFileName == NULL || Content == NULL){
        return;
    }

    getTime(szTimeStr);
    fputs(szTimeStr,fp_);
    snprintf(szLogContent,sizeof(szLogContent)-1,"[%s][%s][%04d][%s]  %s\n",pszFileName,pszFunctionName,codeLine,"info",Content);
    fputs(szLogContent,fp_);

    fflush(fp_);  //刷新文件
}
void MyLog::getTime(char *pszTimeStr){                                                   
    struct tm       tSysTime    = {0};                                            
    struct timeval  tTimeVal    = {0};                                            
    time_t          tCurrentTime = {0};                                           
                                                                                        
    char szUser[20] = {0};                                                        
    char szMsec[20] = {0};                                                        
                                                                                    
    if (pszTimeStr == NULL){                                                      
        return;                                                                   
    }                                                                             
                                                                                  
    tCurrentTime = time(NULL);                                                    
                                                                                  
    localtime_r(&tCurrentTime,&tSysTime);                                         
                                                                                  
    gettimeofday(&tTimeVal,NULL);                                                 
                                                                                  
    sprintf(szUser,"%06d",tTimeVal.tv_usec);                                      
    strncpy(szMsec,szUser,6);                                                     
                                                                                  
    sprintf(pszTimeStr,"[%04d-%02d-%02d %02d:%02d:%02d.%3.6s]",tSysTime.tm_year+1900,tSysTime.tm_mon+1,tSysTime.tm_mday,tSysTime.tm_hour,tSysTime.tm_min,tSysTime.tm_sec,szMsec);
}
