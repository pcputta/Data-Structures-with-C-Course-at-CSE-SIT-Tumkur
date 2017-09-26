#include <stdio.h>
#include <stdlib.h>

#define size 50

int main(int argc, char **argv)
{
	int iVal[size], iSum, i, j, k;

	printf("\nCommand line arguments are\n");

	for(i=0;i<argc;++i)
	{
		printf("%s\t", argv[i]);
	}
	printf("\n");


	for(j=1;j<argc;++j)
	{
		iVal[j] = atoi(argv[j]);
	}

	for(i=1;i<argc;++i)
	{
		iSum+=iVal[i];
	}



	printf("\nSum = %d\n", iSum);
	return 0;
}
