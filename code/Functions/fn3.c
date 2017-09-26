	#include<stdio.h>
	#include<stdlib.h>

	int fnSum(void);

	int main(void)
	{
		int iSum;

		iSum = fnSum();	//no arguments

		printf("%d\n\n", iSum);

		return 0;
	}

	/*Function with return values but no parameters*/

	int fnSum(void)		//no parameters
	{
		int iVal1, iVal2, iRes;

		printf("\nEnter two values\n");
		scanf("%d%d",&iVal1,&iVal2);

		iRes = iVal1 + iVal2;

		printf("\nSum of %d and %d is ", iVal1, iVal2);

		return iRes;
	}
	
