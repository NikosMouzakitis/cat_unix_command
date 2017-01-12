/*A very basic implementation of cat command of Linux.*/
/*Mouzakitis Nikolaos,Crete 2017.*/
#include <stdio.h>
int main(int argc,char *argv[])
{
    int i;
    char ch;

    if(argv < 2)
    {
        printf("Usage error.\n");
        return -1;
    }

    for ( i =1; i < argc; i++)
    {
        FILE *fp;
        fp = fopen(argv[i],"r");

        if(fp == NULL)
        {
            printf("Error opening %s\n",argv[i]);
            return -2;
        }

        while( (ch = fgets(fp)) != EOF)
            printf("%c",ch);

        fclose(fp);
    }
    return 0;
}
