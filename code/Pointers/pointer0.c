#include<stdio.h>
int main() 
{
	int iCount=3;
	int *piCount;
	piCount=&iCount;
	printf("\n Address of iCount = %u\n",&iCount);
	printf("\n Address of iCount = %u\n",piCount);
	printf("\n Value of iCount = %d\n",iCount);
	printf("\n Value of iCount = %d\n",*piCount);
	return 0;
}


