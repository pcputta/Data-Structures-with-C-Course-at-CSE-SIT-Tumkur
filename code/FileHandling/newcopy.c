#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
//    char ptr[100];
//    printf("\nEnter File name\n");
//    scanf("%s",ptr);
//    fp = fopen(ptr,"r");
    fp = fopen(argv[1],"r");
    if(fp != NULL)
    {
        fseek(fp, 0L, SEEK_END);
        printf("\nSize of the file %s is %lu bytes\n",argv[1],ftell(fp));
    }
    else
    {
        printf("\nFile doesn't exist\n");
        exit(0);
    }

    fclose(fp);

    return 0;
}
