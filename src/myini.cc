#include "../include/myini.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


MyIni::~MyIni(){
    fclose(this->fp);
}
void MyIni::LoadConfig(const char *fname){
    this->fp = fopen(fname,"rb");
    if (this->fp == NULL){
        return ;
    }
/*    char config[this->BUFFER_SIZE] = "";
    while((fgets(buf,this->BUFFER_SIZE,fp)) != NULL){
        if (buf[0] == '#'){
            continue;
        }
        config = strcat(config,buf);
    }
    if (config[0] == '\0'){
        return false;
    }
    this.LoadConfigFromString(config);*/
}
bool MyIni::LoadConfigFromString(char *config){
    char buffer[256] = "";
    int len = strlen(config);
    int i = 0;
    int k;
    while (i < len){
        if (config[i] == '['){
            for (int j= i+1,k=0;j<len;j++,k++){
                if (config[j] == '[' ){
                    i = j;
                    break;
                }
                buffer[k] = config[j];
            }
            this->ResolvsSection(buffer);
        }
    }
}
bool MyIni::ResolvsSection(char *str){
//    int len = strlen(str);
    char section[56] = "";
    char key[56] = "";
    char value[56] = "";
    char readline[256] = "";
    int i = 0;
    int j = 0;
    int k = 0;
    while (fgets(readline,255,this->fp) != NULL){
        if (readline[0] == '#' || readline[0] == '\n'){
            continue;
        }
        int len = strlen(readline);
        readline[len-1] = '\0';
        if (readline[0] == '['){
            memset(section,'\0',sizeof(256));
            for (i=0;i<len;i++){
                if (readline[i+1] == ']'){
                    printf("section = %s\n",section);
                    break;
                }
                section[i] = readline[i+1];
            }
            continue;
        }
        if (strlen(section) == 0){
            continue;
        }
        for (i=0;readline[i] != '='&&i<256;i++ ){
            key[i] = readline[i];
        }
        for (j=i+1,k=0;readline[j]!='\0'&&j<256;j++,k++){
            value[k] = readline[j];
        }
        strcpy(this->sectionkey[this->key].section,section);
        strcpy(this->sectionkey[this->key].key,key);
        strcpy(this->sectionkey[this->key].value,value);
        this->key++;

        printf("%s = %s\n",key,value);
        memset(key,'\0',sizeof(256));
        memset(value,'\0',sizeof(256));
        memset(readline,'\0',sizeof(256));
    }
    printf("%d\n",i);
}
char *MyIni::GetSectionKeyValue(const char *section,char *key){
    for (int i=0;i<256;i++){
        if ( strcmp(this->sectionkey[i].section,section) && strcmp(this.sectionkey[i].key,key)){
            return this->sectionkey[i].value;
        }
    }
}
int MyIni::GetSectionKeyValue(const char *section,char *key){
    for (int i=0;i<256;i++){
        if ( strcmp(this->sectionkey[i].section,section) && strcmp(this->sectionkey[i].key,key)){
            return atoi(this->sectionkey[i].value);
        }
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
