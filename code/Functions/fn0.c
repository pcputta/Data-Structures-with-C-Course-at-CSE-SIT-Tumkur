#include<stdio.h>
#include<stdlib.h>

int fnSum(int, int);
int fnMax_Of_Two(int, int);

int iGlobal = 9;

int main(void)
{
	int x=3;
	int iVal1, iVal2, iSum, iMax, iRes;

	printf("\nEnter two values\n");
	scanf("%d%d",&iVal1,&iVal2);

	printf("\nValue of iGlobal = %d\n",iGlobal);

	iSum = fnSum(iVal1,iVal2);	//actual parameters
	printf("\nSum of %d and %d is %d\n",iVal1,iVal2,iSum);
	iSum = fnSum(2,3);
	printf("\nSum of %d and %d is %d\n",2,3,iSum);

	iMax = fnMax_Of_Two(iVal1,iVal2);
	printf("\nMax of %d and %d is %d\n",iVal1,iVal2,iMax);

	printf("\nValue of iGlobal = %d\n",iGlobal);
	return 0;
}

/*Function with return values also has parameters*/

int fnSum(int iX, int iY)		//formal parameters
{
	int iRes;

	iRes = iX + iY;
	iGlobal++;
	printf("\nValue of iGlobal = %d\n",iGlobal);
//	printf("\nValue of iRes = %d",iRes);
	return iRes;

}

int fnMax_Of_Two(int iX, int iY)	//formal parameters
{
	printf("\nValue of iGlobal = %d\n",iGlobal);
	if(iX > iY)
		return iX;
	else
		return iY;
}
