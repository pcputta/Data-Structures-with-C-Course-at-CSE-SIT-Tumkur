#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int count;
    
	if(argc<2)
	{
		printf("\nInsufficient parameters\n");
		return -1;
	}

    fp = fopen(argv[1],"r");
    if(fp != NULL)
    {
    	count = 0;
		while(!feof(fp))
		{
			getc(fp);
			count++;
		}
        printf("\nNumber of characters in the file %s is %d\n",argv[1], count);
    }
    else
    {
        printf("\nFile doesn't exist\n");
        exit(0);
    }

    fclose(fp);

    return 0;
}
