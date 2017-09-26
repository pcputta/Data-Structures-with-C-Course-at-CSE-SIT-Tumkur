	#include<stdio.h>

	void fnSwap(int,int);

	int main(void)
	{
		int iVal1,iVal2;

		printf("\nEnter the values\n");
		scanf("%d%d",&iVal1,&iVal2);

		printf("\nValues before Swapping\n");
		printf("%d\t%d",iVal1,iVal2);

		fnSwap(iVal1,iVal2);

		printf("\nValues after Swapping\n");
		printf("%d\t%d\n",iVal1,iVal2);

		return 0;
	}

	void fnSwap(int iX,int iY)
	{
		int iTemp;

		printf("\nInside Function Values before Swapping\n");
		printf("%d\t%d",iX,iY);
		iTemp = iX;
		iX = iY;
		iY = iTemp;
		printf("\nInside Function Values after Swapping\n");
		printf("%d\t%d",iX,iY);
	}
	









