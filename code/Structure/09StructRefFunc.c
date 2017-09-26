#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int iNum,iDen;
}fraction_t;

void fnSetFraction(fraction_t*);
void fnShowFraction(fraction_t);
fraction_t fnAddFraction(fraction_t, fraction_t);

int main()
{
    fraction_t f1,f2,f3;

    printf("\nEnter value for Fraction1\n");
    fnSetFraction(&f1);

    printf("\nEnter value for Fraction2\n");
    fnSetFraction(&f2);

    f3 = fnAddFraction(f1,f2);

    printf("\nFraction1 : ");
    fnShowFraction(f1);
    printf("\nFraction2 : ");
    fnShowFraction(f2);
    printf("\nFraction3 : ");
    fnShowFraction(f3);

    return 0;
}

void fnSetFraction(fraction_t *f)
{
    printf("\nNumerator : ");
    scanf("%d", &f->iNum);
    printf("\nDenominator : ");
    scanf("%d", &f->iDen);
}
void fnShowFraction(fraction_t f)
{
    printf("%d/%d",f.iNum, f.iDen);
}
fraction_t fnAddFraction(fraction_t a, fraction_t b)
{
    fraction_t sum;
    sum.iNum = (a.iNum * b.iDen) + ( b.iNum * a.iDen);
    sum.iDen = a.iDen*b.iDen;
    return sum;
}

