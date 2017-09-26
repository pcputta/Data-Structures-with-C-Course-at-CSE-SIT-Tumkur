/*pg 28 and 293 in second 183*/
#include<stdio.h>
#include<stdlib.h>

//void fnSwap(int, int);
void fnSwap(int p, int q);
//void fnRealSwap(int *, int *);
void fnRealSwap(int *p, int *q);
void fnRotate(int*, int*, int*);

int main(void)
{
	int iVal1, iVal2, ival3,iSum, iDiff;

	printf("\nEnter two values\n");
	scanf("%d%d",&iVal1,&iVal2);

	printf("\nValues before swap %d and %d\n\n", iVal1, iVal2);

	fnRotate(&iVal1,&iVal2,&iVal3);

	//fnSwap(iVal1,iVal2);	//arguments
	fnRealSwap(&iVal1,&iVal2);	//arguments

	printf("\nValues after swap %d and %d\n\n", iVal1, iVal2);

	return 0;
}

void fnSwap(int p, int q)		//parameters
{
	int iTemp;

	iTemp = p;

	p = q;

	q = iTemp;

	printf("\nValues within function %d and %d\n\n", p, q);


}


void fnRealSwap(int *p, int *q)		//parameters
{
	int iTemp;

	iTemp = *p;

	*p = *q;

	*q = iTemp;

}

void fnRotate(int *p, int *q, int *r)		//parameters
{
	int iTemp;

	iTemp = *p;

	*p = *q;

	*q = *r;

	*r = iTemp;

}


