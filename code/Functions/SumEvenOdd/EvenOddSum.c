/***************************************************************************
*File		: 11SumEvenOdd
*Description	: Program to find sum of odd numbers sum of even numbers
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 10.04
*Date		: 4 July 2012
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "sumEvenOdd.h"

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
    int iaArr[100],iNum,i,iOddSum=0,iEvenSum=0;


    printf("\nEnter the number of Values\n");
    scanf("%d",&iNum);

    printf("\nEnter the values\n");
    for(i=0;i<iNum;i++)
    {
        scanf("%d",&iaArr[i]);
    }

    for(i=0;i<iNum;i++)
    {
	if(0 == iaArr[i]%2)
	{
		iEvenSum += iaArr[i];
	}
	else
	{
		iOddSum += iaArr[i];
	}
    }

	printf("\nEvenSum = %d\nOddSum = %d\n",iEvenSum,iOddSum);


    return 0;
}
