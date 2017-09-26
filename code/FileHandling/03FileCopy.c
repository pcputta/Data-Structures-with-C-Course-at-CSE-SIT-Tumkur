#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp1,*fp2;
    int ch;
//    char ptr[100];
//    printf("\nEnter File name\n");
//    scanf("%s",ptr);
//    fp1 = fopen(ptr,"r");

	if(argc<3)
	{
		printf("\nInsufficient parameters\n");
		return -1;
	}
    fp1 = fopen(argv[1],"r");

    if(fp1 != NULL)
    {

        fp2 = fopen(argv[2],"w");
        while((ch=fgetc(fp1)) != EOF)
        {
            fputc(ch,fp2);
        }
        printf("\nFile %s successfully created\n",argv[2]);
    }
    else
    {
        printf("\nFile %s doesn't exist\n", argv[1]);
        exit(0);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
