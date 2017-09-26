#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;
	int i=0;
	char line[80], ch;
    fp1 = fopen("file.dat","w");

    if(fp1 == NULL)
    {
        printf("\nCannot open file\n");
        return;
    }

	printf("\nEnter 5 lines of text\n");
    while(i++!=5)
    {
        gets(line);
        fprintf(fp1,"%s\n",line);
    }
    fclose(fp1);

    fp2 = fopen("file.dat", "r");

    while(fscanf(fp2,"%[^\n]",line)!=EOF)
    {
        ch = fgetc(fp2);
        printf("%s\n",line);
    }
    fclose(fp2);

    return 0;
}
