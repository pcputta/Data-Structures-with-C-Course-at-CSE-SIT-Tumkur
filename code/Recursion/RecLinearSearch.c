#include <stdio.h>

int fnRecLinSearch(int [], int, int);

int main()
{
	int iKey, iPos, iaList[50], iNum, i;
	
	printf("\nEnter the number of elements\n");
	scanf("%d", &iNum);
	
	printf("\nEnter %d elements\n", iNum);
	for(i=0; i<iNum; i++)
	{
		scanf("%d", &iaList[i]);
	}
	
	printf("\nEnter the key element to be searched\n");
	scanf("%d", &iKey);
	
	iPos = fnRecLinSearch(iaList, iKey, iNum);
	
	if(iPos == -1)
		printf("\n%d is not found\n", iKey);
	else
		printf("\n%d found at %d position\n", iKey, iPos);

	return 0;	
}


int fnRecLinSearch(int iaArr[], int k, int n)
{
	if(n < 0)
		return -1;
	else if(iaArr[n-1] == k)
		return n;
	else
		return fnRecLinSearch(iaArr, k, n-1);
}
