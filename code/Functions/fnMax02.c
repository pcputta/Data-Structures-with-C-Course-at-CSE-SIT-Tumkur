#include<stdio.h>
#include<stdlib.h>
// FUNCTION PROTOTYPE
int fnMax(void);

//int fnPow(int a, int b);

int main(void)
{
	int iRes;
	iRes = fnMax();		//Call to Function

	printf("\nMax is%d\n", iRes);
	return 0;
}

// FUNCTION DEFINITION
int fnMax(void)	//function header
{
	int iA, iB;
	printf("\nEnter the 1st value\n");
	scanf("%d", &iA);

	printf("\nEnter the 2nd value\n");
	scanf("%d", &iB);

	if(iA>iB)
		return iA;
	else
		return iB;
}


