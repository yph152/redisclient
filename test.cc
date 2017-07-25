#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int flag;
    int fd = open("./test",O_RDONLY);
    int nread = 0;
    char buffer[256] = "";
    char dst[256]="";
    int len = 0;
    if (dst[0] == '\0'){
        printf("hello world!\n");
    }
    
/*    for(int j=0;j<1;j++){
        nread = read(fd,buffer,256);
        for(int i= 0;i < 256;i++)
        {
            if(buffer[i] == 0xFF ){

                printf("len = %d",i);
            }
        }
       // printf("nread=%s\n",buffer);
        printf("nread=%d\n",nread);
       // int len = strlen(buffer);*/
       /* for(int i=0;i<24;i++){
            if (buffer[i] == '\n'){
                buffer[i] = '\0';
                strcpy(dst,buffer);
                len = strlen(dst);
                printf("%s  ",dst);
               // printf("len=%d\n",len);
                lseek(fd,len+1-24,SEEK_CUR);

                break;
            }
        }*/
   // }
    
    close(fd);
    return 0;
}
