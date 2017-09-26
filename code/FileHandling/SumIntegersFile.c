#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f1, *f2;
	int number, i, sum = 0;

	printf("\nEnter numbers into the file\n");
	f1 = fopen("DATA", "w");

	for(i=0;i<5;i++)		//for(;;)
	{
		scanf("%d", &number);
		putw(number, f1);
	}
	fclose(f1);

	f1 = fopen("DATA", "r");

	while((number = getw(f1)) != EOF)
	{
	    sum += number;
	}
	fclose(f1);

	f2 = fopen("DATA", "r");
	printf("\nContents of Data File\n\n");
	while((number = getw(f2)) != EOF)
		printf("%4d", number);
	printf("\n");
	fclose(f2);
		
	f1 = fopen("DATA", "a");
	putw(sum, f1);

	fclose(f1);

	f2 = fopen("DATA", "r");
	printf("\nContents of Data File\n\n");
	while((number = getw(f2)) != EOF)
		printf("%4d", number);
	printf("\n");
	fclose(f2);

	return 0;
}
