#include <stdio.h>									/*CPP*/
//#include <conio.h>
int binsrch(int a[],int x, int low, int high)
{
	int mid;

	if(low > high)
	return(-1);
	mid = (low + high)/2;
	return(x == a[mid] ? mid : x < a[mid] ? binsrch(a, x, low, mid-1): binsrch(a, x, mid+1, high));
}


main()
{
	int n,i,pos = 0,key,ch,a[50];

//	clrscr();
	printf("\nBINARY SEARCH\n");
	printf("=================");
	printf("\nEnter number of elements in the array\n");
	scanf("%d",&n);

	printf("\nEnter array elements in ascending order\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(;;)
	{
		printf("\nEnter your choice\n1.Search\n2.Exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			printf("\nEnter element to be searched\n");
			scanf("%d",&key);

			pos = binsrch(a,key,0,n-1);

			if((pos+1) == 0)
			{
				printf("Element %d not found in the array\n",key);
			}
			else
			{
				printf("Element %d found at position %d in the array\n",key,pos+1);
			}
			break;
		case 2: exit(0);
		}
	}

}



/*CPP*/
