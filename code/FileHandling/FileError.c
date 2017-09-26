#include <stdio.h>

int main ()
{
	FILE *fp;
	int c;

	fp = fopen("file.txt","r");
	if(fp == NULL) 
	{
		perror("Error in opening file");
		return(-1);
	}
	while(1)
	{
		c = fgetc(fp);
		if( feof(fp) )
		{ 
			printf("\nReached end of File\n");
			break ;
		}
		printf("%c", c);
	}
	fclose(fp);
	return(0);
}
