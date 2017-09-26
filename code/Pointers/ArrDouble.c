#include<stdio.h>

void fnDouble(int*, int);

int main(void)
{
	int iaArr[100], n, i;

	printf("Enter the no of elements\n");
	scanf("%d",&n);
	printf("\nEnter %d elements\n",n);

	for(i=0;i<n;i++)
		scanf("%d",&iaArr[i]);

	printf("\nElements of the array are\n");
	for(i=0;i<n;i++)
		printf("%d\t",iaArr[i]);

	fnDouble(iaArr,n);

	printf("\nElements of the array after doubling\n");
	for(i=0;i<n;i++)
		printf("%d\t",iaArr[i]);

	return 0;
}

void fnDouble(int *p, int n)
{
	int i;
	for(i=0;i<n;i++)
		p[i] = p[i]*2;
}
	
