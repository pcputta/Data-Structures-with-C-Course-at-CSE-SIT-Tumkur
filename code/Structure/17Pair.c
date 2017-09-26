#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int iVal1, iVal2;
}pair_t;

void fnSwap(int*, int*);
void fnDisplay(pair_t);

int main()
{
	pair_t p;

	p.iVal1 = 35;
	p.iVal2 = 56;

	fnDisplay(p);

	fnSwap(&p.iVal1, &p.iVal2);

	fnDisplay(p);

	return 0;
}

void fnSwap(int *m, int *n)
{
	int t;
	t = *m;
	*m = *n;
	*n = t;
}

void fnDisplay(pair_t a)
{
	printf("\n(%d,%d)\n", a.iVal1, a.iVal2);

}	


	

