#include <stdio.h>
#include <stdlib.h>

typedef union{
	char c;
	int i;
	double d;
}gentype_t;

typedef struct{
	gentype_t val;
	int val_type;
}Array_t;

int main()
{
	Array_t GenArr[10];
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
					scanf("%c", &GenArr[i].val.c);
					GenArr[i].val_type = 1;
					break;

			case 2: printf("\nEnter an integer : ");
					scanf("%d", &GenArr[i].val.i);
					GenArr[i].val_type = 2;
					break;

			case 3: printf("\nEnter an double : ");
					scanf("%lf", &GenArr[i].val.d);
					GenArr[i].val_type = 3;
		}
	}

	printf("\nContents of the generic array\n");

	for(i=0;i<iNum;i++)
	{
	    switch(GenArr[i].val_type)
	    {
	        case 1: printf("%c\t",GenArr[i].val.c); break;
	        case 2: printf("%d\t",GenArr[i].val.i); break;
	        case 3: printf("%lf\t",GenArr[i].val.d); break;
	    }
	}
    printf("\n\n");
	return 0;
}

