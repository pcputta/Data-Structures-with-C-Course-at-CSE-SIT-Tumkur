#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
	int i, iNum;
	FILE *fp;
	char ch;

	printf("\nEnter value of n");
	scanf("%d", &iNum);

	printf("\n\n");	

	fp = fopen("random.dat", "w");

	srand(time(NULL));
	for(i=0;i<iNum;i++)
	{
		ch = (rand()%26)+65;
		fprintf(fp,"%c",ch);
	}

	printf("\n\n");
	fclose(fp);

	fp = fopen("random.dat", "r");

	printf("\n\n");

	while((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
	}
	printf("\n\n");

	fseek(fp,0L,0);

	while(feof(fp)==0)
	{
		fseek(fp,5L,1);
		ch = fgetc(fp);
		printf("%c\t", ch);
	}
	return 0;
}
