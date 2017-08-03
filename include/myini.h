#ifndef MYINI_H_
#define MYINI_H_
#include <stdio.h>

struct Sectionkeypair{
    char section[56];
    char key[56];
    char value[56];
};
class MyIni
{
    public:
        MyIni(){}
        ~MyIni();
        void InitConfig(const char *fname);
        char *GetSectionKeyValue(const char *section,const char *value);
        int GetSectionKeyValueNum(const char *section,char *value);
    private:
        bool resolvsSection();
    private:
        FILE *fp_;
        Section_key_pair sectionkey_[256];
};
#endif
