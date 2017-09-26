/*fseek(fp,0L,0);*/
/*fseek(fp,0L,1);*/
/*fseek(fp,0L,2);*/

/*fseek(fp,m,0);*/
/*fseek(fp,m,1);*/
/*fseek(fp,-m,1);*/
/*fseek(fp,-m,2);b*/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char line[80],ch;
	int size;

	printf("\nEnter a line of text\n");
	gets(line);

	fp = fopen("sample.dat", "w");

	fprintf(fp,"%s", line);
	fclose(fp);

	fp = fopen("sample.dat", "r");
	fseek(fp, -1L, SEEK_END);
	size = ftell(fp);

	while(size)
	{
		ch = fgetc(fp);
		putchar(ch);
		fseek(fp, -2L, SEEK_CUR);
		size--;
	}
	ch = fgetc(fp);
	putchar(ch);
	printf("\n");
	return  0;
}








