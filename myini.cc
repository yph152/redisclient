#include "include/myini.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = 0;
int len = -1;
MyIni::MyIni(const char *fname){
    buffer = ""
    fd = open(fname,O_RDONLY);
    if fd < 0{
        printf("error fd is < 0!\n");
        return
    }
}
MyIni::~MyIni(){
    close(fd)
}
MyIni::LoadFile(const char *fname){
    buffer = ""
    fd = open(fname,O_RDONLY);
    if fd <0 {
        printf("error fd is < 0!\n");
        return
    }
}
char **MyIni::GetAllSection(){
    char buf[256];
    while((readline = this.ReadLine()) != ""){
        if (readline[0] == '['){
            for (int i=0;i<256;i++){
                if (readline[i] != ']')
                {
                    buf[i] = readline[i+1];
                }
                buf[i] = '\0';
            }
        }
    }
}
char *Myini::ReadLine(){
    char dst[256] = "";
    int nread = 0;
    if (buffer != ""){
        for (int i=flag+1;i<len;i++){
            if (buffer[i] == '\n'){
                buffer[i] = '\0';
                strcpy(dst,buffer,i);
                flag = i;
                if (i == len){
                    buffer = "";
                    flag = 0;
                    len = -1;
                }
                return dst;
            }

        }
        return "";
    }else{
        nread = read(fd,buffer,256);
        if (buffer != ""){
            int j = 0;
            for (int i=256;i>0;i--){
                j++;
                if (buffer[i] == '\n'){
                    len = 256 - j+1
                    lseek(fd,-j+1,SEEK_CUR)
                }
            }
            for (int i=0;i<len;i++){
                if (buffer[i] == '\n'){
                    buffer[i] == '\0';
                    strcpy(dst,buffer,i);
                    flag = i;
                    return dst；
                }
            }
            return "";
        }
        return "";
    }
}
/*char *MyIni::ReadLine(){
    char buffer[64];
    char dst[64]
    int nread = 0;
    int len = 0;
    int readlen;;
    while((nread = read(fd,buffer,64))){
        readlen = strlen(buffer);
        if(buffer[readlen] != 0xFF){
            for(int i=0;i<64;i++){
                if(buffer[i] == '\n'){
                    buffer[i] == '\0';
                    strcpy(dst,buffer);
                    len = strlen(dst);
                    lseek(fd,(len+1-64),SEEK_CUR);
                    return dst;
                }
            }
        }else{
            for(int i=0;i<64;i++){
                if(buffer[i] == '\n'){
                    buffer[i] == '\0';
                    strcpy(dst,buffer);
                    len = strlen(dst);
                    flaglen = flaglen + len +1
                    lseek(fd,flaglen,SEEK_CUR);
                    return dst;
                }
            }
        }
    }
    flag = 0;
    return "";
}*/
char *MyIni::GetSectionAllSectionKey(const char *section){

}
int *MyIni::GetSectionKeyValue(const char *section,const char *key){

}
char *Myini::GetSectionKeyValue(const char *section,const char *key){
    char buf[256] = "";
    char *readline = nil;
    int nread = 0;
    while( readline = this.Readline()){
        if (readline[0] == '['){
            for(int i=0;i<256;i++){
                if (readline[i+1] != ']'){
                    buf[i] = readline[i+1];
                }
                if strcmp(buf[i],section){
                    while(readline = this.Readline()){
                        for (int i=0;i<256;i++){
                            if (readline[0] == '#'){
                                break;
                            }else if(readline[i] != '\0'){
                                buf[i] = readline[i];
                            }else{
                                if strcmp(buf,key){
                                    len = strlen(key);
                                    for(int j=len+1;j<256;j++){
                                        if(readline[j+1] != '\0'){
                                            buf[j-len-1] = readline[j+1];
                                        }
                                        return buf;
                                    }
                                }
                            }
                        }
                    }
                }


            }
        }
    }
}
