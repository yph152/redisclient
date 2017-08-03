#include "../include/myini.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int keys = 0;
const static int BUFFER_SIZE = 1024;

MyIni::~MyIni(){
    if (fp_ != NULL){
        fclose(fp_);
    }
}
void MyIni::InitConfig(const char *fname){
    this->fp = fopen(fname,"rb");
    if (this->fp == NULL){
        return ;
    }
    resolvsSection();
}
bool MyIni::ResolvsSection(){
    char section[56] = "";
    char key[56] = "";
    char value[56] = "";
    char readline[256] = "";
    int i = 0;
    int j = 0;
    int k = 0;
    while (fgets(readline,255,fp_) != NULL){
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
            section[i+1] = '\0';
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
        strcpy(sectionkey_[keys].section,section);
        strcpy(sectionkey_[keys].key,key);
        strcpy(sectionkey_[keys].value,value);

        printf("%s = %s\n",sectionkey_[keys].key,sectionkey_[keys].value);
        keys++;

        printf("%s = %s\n",key,value);
        memset(key,'\0',sizeof(256));
        memset(value,'\0',sizeof(256));
        memset(readline,'\0',sizeof(256));
    }
    printf("%d\n",i);
}
char *MyIni::GetSectionKeyValue(const char *section,const char *key){
    for (int i=0;i<2;i++){
//        printf("section = %s\n%s = %s\n",this->sectionkey[i].section,this->sectionkey[i].key,this->sectionkey[i].value);
        if ( (strcmp(this->sectionkey[i].section,section)==0) && (strcmp(this->sectionkey[i].key,key)==0)){
            return this->sectionkey[i].value;
        }
    }
}
int MyIni::GetSectionKeyValueNum(const char *section,char *key){
    for (int i=0;i<256;i++){
        if ( strcmp(this->sectionkey[i].section,section) && strcmp(this->sectionkey[i].key,key)){
            return atoi(this->sectionkey[i].value);
        }
    }
}

