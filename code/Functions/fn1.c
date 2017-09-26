	/*pg 28 and 293 in second 183*/
	#include<stdio.h>
	#include<stdlib.h>

	void fnSumDiff(int, int, int*, int*);

	int main(void)
	{
		int iVal1, iVal2, iSum, iDiff;

		printf("\nEnter two values\n");
		scanf("%d%d",&iVal1,&iVal2);

		fnSumDiff(iVal1,iVal2,&iSum,&iDiff);	//arguments

		printf("\nSum of %d and %d is %d\n\n", iVal1, iVal2, iSum);
		printf("\nDiff of %d and %d is %d\n\n",iVal1,iVal2,iDiff);
		return 0;
	}

	/*Function with return values and parameters*/

	void fnSumDiff(int iX, int iY, int *s, int *d)		//parameters
	{
		int iRes;
	
		iRes = iX + iY;

		*s = iRes;

		iRes = iX - iY;

		*d = iRes;

	}

	
