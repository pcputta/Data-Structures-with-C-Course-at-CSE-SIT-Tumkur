#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char **argv )
{
	char fname[30], word[20], pattern[30];
	int i;
	FILE *fp;

/*	printf("\nEnter File Name\n");*/
/*	scanf("%s", fname);*/

	strcpy(fname, argv[1]);
	strcpy(pattern, argv[2]);

	fp = fopen(fname, "r");

	if(fp==NULL)
	{
		printf("\nFile does not exist");
		return -1;
	}

	while(fscanf(fp,"%s",word)!=EOF)
	{
/*		printf("\n%s", word);*/
		if(!strcmp(word,pattern))
		{
			printf("\nFound at %ld position\n", ftell(fp)-strlen(pattern));
			getchar();
		}	
	}

	return 0;
}
