#ifndef MYINI_H_
#define MYINI_H_
#include <stdio.h>
struct Section_key_pair{
    char section[56];
    char key[56];
    char value[56];
};
class MyIni
{
    public:
        MyIni(){}
        ~MyIni();
        void LoadConfig(const char *fname);
        char *GetSectionKeyValue(const char *section,const char *value);
        int GetSectionKeyValueNum(const char *section,char *value);
        bool LoadConfigFromString(char *config);
        bool ResolvsSection(char *string);
    private:
        FILE *fp;
        const static int BUFFER_SIZE = 1024;
        Section_key_pair sectionkey[256];
//        static int keys;
};
#endif
