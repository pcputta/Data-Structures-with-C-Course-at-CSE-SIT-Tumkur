#include<stdio.h>
#include<stdlib.h>

void fnSum(void);

int main(void)
{
	fnSum();	//no arguments
	return 0;
}

/*Function with no return values and no parameters*/

void fnSum(void)		//no parameters
{
	int iVal1, iVal2, iRes;

	printf("\nEnter two values\n");
	scanf("%d%d",&iVal1,&iVal2);
	
	iRes = iVal1 + iVal2;

	printf("\nSum of %d and %d is %d\n",iVal1,iVal2,iRes);
}
