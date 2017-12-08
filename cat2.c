#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define SIZE 8

int main(int argc,char *argv[])
{
        /*usage check*/
  
        if(argc != 2) {
        printf("Usage error\n");
        exit(-1);
        }

        int fd;
        char *file;
        char buffer[SIZE];
        file = (char *) malloc(strlen(argv[1]) + 1);
        int retval;
        
        if(file == NULL) {
                printf("malloc failed\n");
                exit(-1);
        }
        strcpy(file,argv[1]);
        
        if( ( fd = open(file,O_RDWR)) == -1) {
                printf("/open failed\n");
                exit(-1);
       }
        
        while( ( retval = read(fd,buffer,SIZE) ) > 0 ) {
                write(1,buffer,retval); //write in console.
               
        putchar('\n');
        
        return 0;
}
