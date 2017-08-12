#include <stdarg.h>
#include <stdio.h>

#define log(format,...)    LOG(format,##__VA_ARGS__)

void LOG(const char *format,...){
    char test[56] = {0};
    va_list ap;
    va_start(ap,format);
    vsprintf(test,format,ap);
    printf("%s",test);
    va_end(ap);
}
int main(){
/*    char str[56] = "hello world";
    log("test%s  \n",str);*/
    char *str = "set";
    int ret = str%10;
    printf("%d\n",ret);
}
