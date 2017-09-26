/********************************************************************************
*File		: BubbleSort.c
*Description	: Program to recusively search for a element using Linear Search
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 8.10
*Date		: 27 July 2010
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int [], int);
void fnGenRandInput(int [], int);
//void fnGenRandInput(int*, int);
//void fnGenRandInput(int a[], int n);
void fnDispArray( int [], int);

/******************************************************************************
*Function	: main
*Input parameters:
*	int argc - no of commamd line arguments
*	char **argv - vector to store command line argumennts
*RETURNS	:	0 on success
******************************************************************************/

int main( int argc, char **argv)
{

	int Arr[1000],iNum,iPos,iKey,i;

	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);

	/*char acstr[20];
	scanf("%s",acStr);
	scanf("%s",&acStr[0]);*/


	fnGenRandInput(Arr,iNum);
	//fnGenRandInput(&Arr[0],iNum);

	printf("\nUnsorted Array\n");
	fnDispArray(Arr,iNum);

	BubbleSort(Arr,iNum);


	printf("\nSorted Array\n");
	fnDispArray(Arr,iNum);

	return 0;

}


/******************************************************************************
*Function	: BubbleSort
*Description	: Function to sort elements in an array using Bubble Sort
*Input parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	: no return value
******************************************************************************/

void BubbleSort(int X[], int n)
{
	int i,j,iTemp,iMin;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(X[i] > X[j])
			{
				iTemp = X[i];
				X[i] = X[j];
				X[j] = iTemp;
			}
		
		}

	}
}

/******************************************************************************
*Function	: GenRandInput
*Description	: Function to generate a fixed number of random elements
*Input parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	:no return value
******************************************************************************/


//fnGenRandInput(Arr,iNum);
void fnGenRandInput(int X[], int n)
{
	int i;	
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		X[i] = rand()%10000;
	}
	/*for(i=0;i<n;i++)
	{
		scanf("%d",&X[i]);
	}*/

}

/******************************************************************************
*Function	: DispArray
*Description	: Function to display elements of an array
*Input parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	: no return value
******************************************************************************/

void fnDispArray( int X[], int n)
{
	int i;

	for(i=0;i<n;i++)
		printf(" %d \n",X[i]);

}
