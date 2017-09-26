#include <stdio.h>
#include <stdlib.h>

typedef union{
	char c;
	int i;
	double d;
}mytype_t;

int main()
{
	mytype_t x,y,z;

	x.c = '1';
	y.i = 65;
	z.d = 245.3;

	printf("\n%c", x.c);		
	printf("\n%c", y.c);			//character 'A'
	printf("\n%c", z.c);
	printf("\n\\\\\\\\\\\\\\\\\\");

	y.d = 234.4556;
	printf("\n%d", x.i);
	printf("\n%d", y.i);
	printf("\n%d", z.i);
	printf("\n\\\\\\\\\\\\\\\\\\");

	printf("\n%lf", x.d);
	printf("\n%lf", y.d);
	printf("\n%lf", z.d);
	printf("\n\\\\\\\\\\\\\\\\\\");
	return 0;
}

