#include <stdio.h>
#include "include/myini.h"

int main()
{
    MyIni ini;
    char fname[10] = "./test";
    ini.LoadFile(fname);
    char *str = ini.ReadLine();
    printf("test...\n",str);
    return 0;
}
