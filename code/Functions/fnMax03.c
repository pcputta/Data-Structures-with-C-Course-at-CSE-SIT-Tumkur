#include<stdio.h>
#include<stdlib.h>
// FUNCTION PROTOTYPE
void fnMax(int, int);

//int fnPow(int a, int b);

int main(void)
{
	int iM,iN,iRes;

	printf("\nEnter the 1st value\n");
	scanf("%d", &iM);

	printf("\nEnter the 2nd value\n");
	scanf("%d", &iN);

	fnMax(iM, iN);		//Call to Function

	return 0;
}

// FUNCTION DEFINITION
void fnMax(int iA, int iB)	//function header
{
	int iMax;				//body of the function
	if(iA>iB)
		iMax = iA;
	else
		iMax = iB;
	printf("\nMax of %d and %d is %d\n", iA, iB, iMax);
}


