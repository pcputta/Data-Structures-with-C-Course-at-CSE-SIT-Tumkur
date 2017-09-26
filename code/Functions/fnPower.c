#include<stdio.h>
#include<stdlib.h>
// FUNCTION PROTOTYPE
int fnPow(int, int);

//int fnPow(int a, int b);

int main(void)
{
	int iX,iN,iRes;

	printf("\nEnter the value of x\n");
	scanf("%d", &iX);

	printf("\nEnter the value of n\n");
	scanf("%d", &iN);

	iRes = fnPow(iX, iN);		//Call to Function

	printf("\n%d power %d is %d\n", iX, iN, iRes);
	return 0;
}

// FUNCTION DEFINITION
int fnPow(int iA, int iB)	//function header
{				//body of the function
	int i,iVal=1;		//local declarations

	for(i=0;i<iB;i++)
		iVal = iVal * iA;

	return iVal;
}
