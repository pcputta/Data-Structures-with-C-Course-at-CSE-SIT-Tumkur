#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	
	for(i=0 ; i<argc ; i++)
	{
		printf("\n%d : %s", i, argv[i]);
	}
	
	return 0;
}




/*
	char string[30];
	char *string;

	
	
	char strings[10][30];
	char **strings;
*/













