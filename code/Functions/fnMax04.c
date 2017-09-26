#include<stdio.h>
#include<stdlib.h>
// FUNCTION PROTOTYPE
void fnMax(void);

//int fnPow(int a, int b);

int main(void)
{
	fnMax();		//Call to Function
	return 0;
}

// FUNCTION DEFINITION
void fnMax(void)	//function header
{
	int iA, iB;
	printf("\nEnter the 1st value\n");
	scanf("%d", &iA);

	printf("\nEnter the 2nd value\n");
	scanf("%d", &iB);

	if(iA>iB)
		iMax = iA;
	else
		iMax = iB;
	printf("\nMax of %d and %d is %d\n", iA, iB, iMax);
}


