#include <stdio.h>
#include "include/myini.h"

int main()
{
    MyIni ini;
    char fname[10] = "./test";
    ini.LoadConfig(fname);
    ini.ResolvsSection(fname);
   // printf("test...\n",str);
    return 0;
}
