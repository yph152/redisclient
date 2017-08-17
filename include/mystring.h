#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <stdio.h>

#define BUFFER_SIZE  1024

class mystring{
    public:
        mystring();
        mystring(const mysring &);
        mystring(const char *);
        ~mystring();
    public:
        char& operator[](const int);
        mystring& operator=(const mystring&);
        mystring& operator+=(const mystring&);
        mystring operator+(const mystring lhs,const mystring& rhs);
        isEmpty();
        length();
        clear();
        const char *c_str();

    private:
        int len;
        int free;
        char *buf;
};


#endif
