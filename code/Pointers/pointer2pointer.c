#include <stdio.h>
#include <stdlib.h>
int main()
{
	int p, *q, **r;
	p = 10;
	q = &p;
	r = &q;

	printf("\nAddress of p = %p\n", &p);
	printf("\nValue of p = %d\n", p);
	printf("\nAddress of q = %p\n", &q);
	printf("\nValue stored in address q = %d\n", *q);
	printf("\nAddress of r = %p\n", &r);
	printf("\nValue pointed to by r = %d\n", **r);

	printf("sizeof pointer q is %d\n", sizeof(q));

	return 0;
}
