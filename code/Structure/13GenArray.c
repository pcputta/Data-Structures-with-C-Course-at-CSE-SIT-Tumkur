#include <stdio.h>
#include <stdlib.h>

typedef union{
	char c;
	int i;
	double d;
}mytype_t;

int main()
{
	mytype_t GenArr[10];
	int iaIndexArr[10];
	int iNum, i, iChoice;

	printf("\nEnter no of elements\n");
	scanf("%d", &iNum);

	printf("\nEnter %d elements\n", iNum);
	for(i=0;i<iNum;i++)
	{
		printf("\n1.Character\n2.Integer\n3.Double\n");
		printf("\nEnter your choice\n");
		scanf("%d", &iChoice);
		getchar();

		switch(iChoice)
		{
			case 1: printf("\nEnter an character : ");
					scanf("%c", &GenArr[i].c);
					iaIndexArr[i]=1;
					break;

			case 2: printf("\nEnter an integer : ");
					scanf("%d", &GenArr[i].i);
					iaIndexArr[i]=2;
					break;

			case 3: printf("\nEnter an double : ");
					scanf("%lf", &GenArr[i].d);
					iaIndexArr[i]=3;
		}
	}

	printf("\nContents of the generic array\n");

	for(i=0;i<iNum;i++)
	{
	    switch(iaIndexArr[i])
	    {
	        case 1: printf("%c\t",GenArr[i].c); break;
	        case 2: printf("%d\t",GenArr[i].i); break;
	        case 3: printf("%lf\t",GenArr[i].d); break;
	    }
	}
    printf("\n\n");
	return 0;
}

