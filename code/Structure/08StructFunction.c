#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int iNum,iDen;
}fraction_t;

void fnShowFraction(fraction_t);
fraction_t fnSetFraction();
fraction_t fnAddFraction(fraction_t, fraction_t);

int main()
{
    fraction_t f1,f2,f3;
	fraction_t f4;
    printf("\nEnter value for Fraction1\n");
    f1=fnSetFraction();

    printf("\nEnter value for Fraction2\n");
    f2=fnSetFraction();

    f3 = fnAddFraction(f1,f2);
	f4 = f3;

    printf("\nFraction1 : ");
    fnShowFraction(f1);
    printf("\nFraction2 : ");
    fnShowFraction(f2);
    printf("\nFraction3 : ");
    fnShowFraction(f3);

    return 0;
}

//passing structure as a parameter
void fnShowFraction(fraction_t f)
{
    printf("%d/%d",f.iNum, f.iDen);
}

//function that returns a structure
fraction_t fnSetFraction()
{
    fraction_t a;
    printf("\nNumerator : ");
    scanf("%d", &a.iNum);
    printf("\nDenominator : ");
    scanf("%d", &a.iDen);
    return a;
}

//function that returns a structure and accepts structure as parameter
fraction_t fnAddFraction(fraction_t a, fraction_t b)
{
    fraction_t sum;
    sum.iNum = (a.iNum * b.iDen) + ( b.iNum * a.iDen);
    sum.iDen = a.iDen*b.iDen;
    return sum;
}

