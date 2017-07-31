#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "include/myini.h"
#include "include/mylog.h"

void GetTime(char *pszTimeStr){
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
enum Day {
    Saturday = 0,
    Sunday = 1,
};
int main()
{
    MyLog mylog;
    LogLevel loglevel = WARN;

    mylog.MyLogInit(loglevel,"./test");
    for(int i=0;i<10;i++){
        mylog.Infof("hello world");
        mylog.Warnf("hahhahah");
    }
/*    Day day = Saturday;
    if (day == 0){
        printf("yes...\n");
    }
    printf("[%s][%s %s][%d]\n",__DATE__,__FILE__,__FUNCTION__,__LINE__);
    char str[256] = "hello";
    GetTime(str);
    printf("%s\n",str);
    MyIni ini;
    char fname[10] = "./test";
    ini.LoadConfig(fname);
    ini.ResolvsSection(fname);
    char *str = ini.GetSectionKeyValue("section1","name");
    printf("test...%s\n",str);
  */
     
    return 0;
}
