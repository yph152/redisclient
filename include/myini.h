#ifndef MYINI_H_
#define MYINI_H_
class MyIni
{
    public:
        MyIni(){}
        MyIni(char *fname);
        ~MyIni();
        void LoadFile(const char *fname);
        char *GetAllSection()
        char *GetAllSectionKey(const char *section);
        char *GetSectionKeyValue(const char *section,const char *key);
        char *ReadLine();
        int  GetSectionKeyValue(const char *section,const char *key);
    private:
        int fd;
        char buffer[BUFFER_SIZE];
        const static int BUFFER_SIZE = 256
};
#endif
