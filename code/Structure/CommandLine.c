#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int iVal1, iVal2, iSum, i;

	printf("\nNo of cmd line args is %d\n", argc);	
	if(argc<3)
	{
		printf("\nInsufficient parameters\n");
		return -1;
	}

	printf("\nCommand line arguments are\n");

	for(i=0;i<argc;++i)
	{
		printf("%s\t", argv[i]);
	}
	printf("\n");

	iVal1 = atoi(argv[1]);
	iVal2 = atoi(argv[2]);

	iSum = iVal1 + iVal2;

	printf("\nSum = %d\n", iSum);
	return 0;
}
