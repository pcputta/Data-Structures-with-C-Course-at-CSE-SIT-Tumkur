#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;
    char fname[30];
    unsigned long offset=0;
    int count;
    char ch;
//    char ptr[100];
//    printf("\nEnter File name\n");
//    scanf("%s",ptr);
//    fp1 = fopen(ptr,"r");
    if(argc<2)
	{
		printf("\nInsufficient parameters\n");
		return -1;
	}

    fp1 = fopen(argv[1],"r");

    if(fp1 == NULL)
    {
        printf("\nFile doesn't exist\n");
        exit(0);
    }

    fseek(fp1, 0L, SEEK_END);
/*    count = ftell(fp1);*/
    printf("\nSize of the file %s is %lu bytes\n",argv[1],ftell(fp1));
    strcpy(fname,"Reverse_");
    strcat(fname, argv[1]);
    
    fp2 = fopen(fname, "w");
    do
    {
        fseek(fp1, -1, SEEK_CUR);
        ch = fgetc(fp1);
        if(ch!=EOF)
            fputc(ch, fp2);
/*        offset++;*/
        count--;
    }while(count>=0);

/*    while(!fseek(fp1, -offset, SEEK_END))*/
/*    {*/
/*        fputc(getc(fp1), fp2);*/
/*        offset++;*/
/*    }*/

/*    while(!fseek(fp1, -offset, SEEK_CUR))*/
/*    {*/
/*        fputc(getc(fp1), fp2);*/
/*        offset = 2;*/
/*    } */
    fclose(fp1);
    fclose(fp2);

    printf("\n");
    return 0;
}

