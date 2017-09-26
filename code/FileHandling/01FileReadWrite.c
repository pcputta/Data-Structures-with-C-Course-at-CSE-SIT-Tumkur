#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp1, *fp2;
    char fname[60], dest[60], ch;
//    int i=0;

    printf("\nEnter file name : ");
    scanf("%s", fname);

    fp1 = fopen(fname,"r");
    if(fp1 == NULL)
    {
        printf("\nCannot open file\n");
        return -1;
    }

    printf("\nContents of the file\n");
    while((ch = fgetc(fp1))!=EOF)
    {
        putchar(ch);
    }

    strcpy(dest, "copy_of_");
    strcat(dest,fname);
    fp2 = fopen(dest, "w");
    if(fp2 == NULL)
    {
        printf("\nFailed to create file\n");
        return -1;
    }

    rewind(fp1);

    while((ch = fgetc(fp1))!=EOF)
    {
        fputc(ch,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

