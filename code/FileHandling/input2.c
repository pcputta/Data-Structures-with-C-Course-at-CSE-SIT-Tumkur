#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f1;
	char  c;

	f1 = fopen("INPUT", "w");

	printf("\nENter text\n\n");
	while((c=getchar())!=EOF)
		putc(c,f1);
	fclose(f1);
	return 0;
}
