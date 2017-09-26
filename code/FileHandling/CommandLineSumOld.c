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


	for(j=1;j<argc+1;++j)
	{
		iVal[j] = atoi(argv[j]);
	}

	for(k=1;k<argc+1;++k)
	{
		printf("\nhere\n");
		iSum = iVal[k] + iVal[k+1];
	}

	printf("\nSum = %d\n", iSum);
	return 0;
}
