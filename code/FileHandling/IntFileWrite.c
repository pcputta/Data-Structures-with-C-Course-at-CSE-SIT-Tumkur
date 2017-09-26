#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f1, *f2, *f3;
	int number, i;

	printf("\nEnter numbers into the file\n");
	f1 = fopen("DATA", "w");

	for(i=0;i<10;i++)		//for(;;)
	{
		scanf("%d", &number);
		if(number == -1)	break;
		putw(number, f1);
	}
	fclose(f1);

	f1 = fopen("DATA", "r");
	f2 = fopen("ODD", "w");
	f3 = fopen("EVEN", "w");

	while((number = getw(f1)) != EOF)
	{
		if(number % 2)
			putw(number, f2);
		else
			putw(number, f3);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);

	f2 = fopen("ODD", "r");
	f3 = fopen("EVEN", "r");

	printf("\nContents of ODD File\n\n");
	while((number = getw(f2)) != EOF)
		printf("%4d", number);

	printf("\nContents of EVEN File\n\n");
	while((number = getw(f3)) != EOF)
		printf("%4d", number);

	fclose(f2);
	fclose(f3);
	return 0;
}
