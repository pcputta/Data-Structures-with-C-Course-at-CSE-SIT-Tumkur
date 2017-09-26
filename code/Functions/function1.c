#include <stdio.h>
#include <stdlib.h>

int fnFactorial(int);

int main(void)
{
    int iVal,iFact;
    printf("\nEnter the value whose factorial is to be computed\n");
    scanf("%d",&iVal);

    iFact = fnFactorial(iVal);
//	fnFactorial(8);
//	fnFactorial(iVal+8);
//	fnFactorial(iVal1+iVal2);
//	fnfactorial(fnSomeotherFn());
    printf("\nFactorial of %d is %d\n",iVal,iFact);
    return 0;
}

int fnFactorial(int iNum)
{
    if(iNum > 1)
        return iNum * fnFactorial(iNum -1);
    else
        return 1;
}

