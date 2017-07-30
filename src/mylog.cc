#include "../include/mylog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MyLog::MyLog(){}
MyLog::~MyLog(){}
void MyLog::MyLogInit(LogLvel loglevel,const char *filename){
    loglevel_ = loglevel;
    if (filename) == NULL){
        printf("this filename is null...\n");
        return;
    }
    fp_ = fopen(filename,"ab+");
    if (fp_ == NULL) {
        printf("open file failed...\n");
        return;
    }
    printf("open file success...\n")
}
void MyLog::Info(const char *format,...){
    if (loglevel_ == 0){
        writeLogFile();
    }
}

void MyLog::Warn(const char *format,...){

}
void MyLog::Error(const char *format,...){

}
void MyLog::Debug(const char *format,...){

}
void MyLog::writeLogFile(char *pszFileName,char *pszFunctionName,int codeLine,int loglevel,char *Content){
    char *szLogContent[2048] = {0};
    char *szTimeStr[128] = {0};

    if (pszFileName == NULL || Content == NULL){
        return;
    }

    getTime(szTimeStr);
    fputs(szLogContent,fp);

    snprintf(szLogContent,sizeof(szLogContent)-1,"[%s][%s][%04d][%s]%s\n",pszFileName,pszFunctionName,codeLine,loglevel,Content);
    fputs(szLogContent,fp);

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
    strncpy(szMsec,szUser,3);                                                     
                                                                                  
    sprintf(pszTimeStr,"[%04d.%02d.%02d %02d:%02d:%02d.%3.3s]",tSysTime.tm_year+1900,tSysTime.tm_mon+1,tSysTime.tm_mday,tSysTime.tm_hour,tSysTime.tm_min,tSysTime.tm_sec,szMsec);
}
