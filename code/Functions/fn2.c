	#include<stdio.h>
	#include<stdlib.h>

	void fnSum(int, int);

	int main(void)
	{
		int iVal1, iVal2, iSum;

		printf("\nEnter two values\n");
		scanf("%d%d",&iVal1,&iVal2);

		fnSum(iVal1,iVal2);	//arguments

		return 0;
	}

	/*Function with no return values but has parameters*/

	void fnSum(int iX, int iY)		//parameters
	{
		int iRes;
	
		iRes = iX + iY;

		printf("\nSum of %d and %d is %d\n\n", iX, iY, iRes);

	}
