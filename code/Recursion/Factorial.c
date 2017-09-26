#include <stdio.h>

int fnFactorial(int);

int main()
{
	int iVal, iRes;
	
	printf("\nEnter a value\n");
	scanf("%d", &iVal);
	
	iRes = fnFactorial(iVal);
	
	printf("\nFactorial of %d is %d\n", iVal, iRes);
	return 0;
}

int fnFactorial(int iN)
{
	int iX, iY, iVal;
	
	if(iN == 1)
		return 1;
		
	iX = iN;
	iY = fnFactorial(iN - 1);
	iVal = iX * iY;
	return iVal;
}


