#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;
	int i;
	char line[80];
    fp1 = fopen("file.dat","w+");

    if(fp1 == NULL)
    {
        printf("\nCannot open file\n");
        return;
    }

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
