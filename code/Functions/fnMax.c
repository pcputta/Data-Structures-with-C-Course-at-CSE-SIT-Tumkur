	#include<stdio.h>
	#include<stdlib.h>
	// FUNCTION PROTOTYPE
	int fnMax(int, int);

	int main(void)
	{
		int iM,iN,iRes;

		printf("\nEnter the 1st value\n");
		scanf("%d", &iM);

		printf("\nEnter the 2nd value\n");
		scanf("%d", &iN);

		iRes = fnMax(iM, iN);		//Call to Function

		printf("\n%d Max of %d is %d\n", iM, iN, iRes);
		return 0;
	}

	// FUNCTION DEFINITION
	int fnMax(int iA, int iB)	//function header
	{				//body of the function
		if(iA>iB)
		{
			//iA++;
			return iA;
		}
		else
		{
			//iB--;
			return iB;
		}
	}


