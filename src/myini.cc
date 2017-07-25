#include "../include/myini.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

MyIni::MyIni(const char *fname){
    this->fp = fopen(fname,"rb");
    assert(this->fp != NULL);
}
MyIni::~MyIni(){
    fclose(this->fp);
}
bool MyIni::LoadConfig(const char *fname){
    this->fp = fopen(fname,"rb");
    if (this->fp == NULL){
        return false;
    }
    char config[this->BUFFER_SIZE] = "";
    while((fgets(buf,this->BUFFER_SIZE,fp)) != NULL){

    }
}
bool MyIni::LoadConfigFromString(char *config){

}
bool MyIni::GetSectionKeyValue(const char *section,void *value){
    char config[this->BUFFER_SIZE] = "";
    while((fgets(this->buf,this->BUFFER_SIZE+1,this->fp) != NULL)){
            config = strcat(config,this->buf);
    }
    if(config[0] == '\0'){
        return false;
    }

}
/*
int flag = 0;
int len = -1;
MyIni::MyIni(const char *fname){
    this->buffer = "";
    fd = open(fname,O_RDONLY);
    if (fd < 0){
        printf("error fd is < 0!\n");
        return;
    }
}
MyIni::~MyIni(){
    close(fd);
}
void MyIni::LoadFile(const char *fname){
    this->buffer = "";
    fd = open(fname,O_RDONLY);
    if (fd <0) {
        printf("error fd is < 0!\n");
        return;
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
char *MyIni::ReadLine(){
    char dst[256] = "";
    int nread = 0;
    if (buffer != ""){
        for (int i=flag+1;i<len;i++){
            if (buffer[i] == '\n'){
                buffer[i] = '\0';
                strcpy(dst,buffer);
                flag = i;
                if (i == len){
                    this->buffer = "";
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
                    len = 256 - j+1;
                    lseek(fd,-j+1,SEEK_CUR);
                }
            }
            for (int i=0;i<len;i++){
                if (buffer[i] == '\n'){
                    buffer[i] == '\0';
                    strcpy(dst,buffer);
                    flag = i;
                    return dst;
                }
            }
            return "";
        }
        return "";
    }
}
char *MyIni::ReadLine(){
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
}
char *MyIni::GetSectionKeyValue(const char *section,void *value){
    char buf[256] = "";
    char *readline = NULL;
    int nread = 0;
    while( readline = this->ReadLine()){
        if (readline[0] == '['){
            for(int i=0;i<256;i++){
                if (readline[i+1] != ']'){
                    buf[i] = readline[i+1];
                }
                if (strcmp(buf,section)){
                    while(readline = this->ReadLine()){
                        for (int i=0;i<256;i++){
                            if (readline[0] == '#'){
                                break;
                            }else if(readline[i] != '='){
                                buf[i] = readline[i];
                            }else{
                                if (strcmp(buf,key)){
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
bool mystrcmp(const char *dst,const char *src){
    int len = strlen(dst);
    int len2 = strlen(src);
    if (len != len2){
        return true;
    }
    for (int i=0;i<len;i++){
        if (dst[i] != src[i]){
            return false;
        }
    }
    return true;
}*/
