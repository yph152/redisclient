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
        char *GetSectionKeyValue(const char *section,void *value);
        bool LoadConfigFromString(char *config);
    private:
        FILE *fp;
        const static int BUFFER_SIZE = 1024;
        Section_key_pair sectionkey[256];
};
#endif
