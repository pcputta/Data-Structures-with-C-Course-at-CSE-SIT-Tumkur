#include<stdio.h>
#include<stdlib.h>

void fnReadValues(int*, int*, int*);
void fnCalcAreaVolume(int, int, int, int*, int*);


int main(void)
{
	int iLen, iBrd, iHgt, iSurfArea, iVol;

	fnReadValues(&iLen, &iBrd, &iHgt);

	fnCalcAreaVolume(iLen, iBrd, iHgt, &iSurfArea, &iVol);

	printf("\nSurface Area = %d units\n", iSurfArea);
	printf("\nVolume = %d units\n", iVol);

	return 0;
}


void fnReadValues(int *l, int *b, int *h)
{
	scanf("%d%d%d", l, b, h);

}

void fnCalcAreaVolume(int l, int b, int h, int *s, int *v)
{
	*s = 2*l*b+2*b*h+2*h*l;
	*v = l*b*h;
}







