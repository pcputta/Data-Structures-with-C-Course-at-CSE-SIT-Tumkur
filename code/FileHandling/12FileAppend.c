#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    FILE *fp1,*fp2, *fp3;
    int iWordCount = 0, iLineCount = 0;
    char cCharacter;
    char command[30];

    fp1 = fopen(argv[1],"r");
    fp2 = fopen(argv[2], "r");
    fp3 = fopen(argv[3], "w+");

    while((cCharacter=fgetc(fp1))!=EOF)
    {
        fputc(cCharacter,fp3);
    }

    while((cCharacter=fgetc(fp2))!=EOF)
    {
        fputc(cCharacter,fp3);
    }

/*    rewind(fp3);*/
    fseek(fp3, 0L, SEEK_SET);

    while((cCharacter=fgetc(fp3))!=EOF)
    {
        if(cCharacter == '\n')
        {
            iLineCount++;
            iWordCount++;
        }
        else if(cCharacter == '\t' || cCharacter == ' ')
            iWordCount++;
       printf("%c",cCharacter);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("\n\nNumber of lines is : %d\n", iLineCount);

    printf("\n\nNumber of words is : %d\n", iWordCount);

    //Code for Verification (works only on GNU\Linux)
    strcpy(command, "wc ");
    strcat(command, argv[3]);
    strcat(command, " -lw");
    printf("\nOutput of command : wc %s -lw\n", argv[3]);
    system(command);
    return 0;
}

