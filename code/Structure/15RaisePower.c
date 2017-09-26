
/* y = (x)^n*/
/* log(y) = n log(x)*/
/* y = e^(nlog(x))*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef union{
    float fexp;
    int iexp;
}exp_t;

typedef struct{
    float x;
    char flag;
    exp_t exp;
}value_t;

float power(value_t);

int main()
{
    value_t a;
    int i;
    float n,y;

    printf("y=x^n\n\nEnter a value for x : ");
    scanf("%f", &a.x);
    printf("\nEnter a value for n : ");
    scanf("%f", &n);

    i=(int)n;
    a.flag = (i==n)? 'i' : 'f';

    if(a.flag == 'i')
    {
        a.exp.iexp= i;
    }
    else
    {
        a.exp.fexp= n;
    }

    if(a.flag == 'f' && a.x <= 0.0)
    {
        printf("\nError cannot raise a non positive number\n");
    }
    else
    {
        y = power(a);
        printf("\ny = %.4f\n", y);
    }
    return 0;
}

float power(value_t a)
{
    int i;
    float y = a.x;
    if(a.flag == 'i')
    {
        if(a.exp.iexp == 0)
        {
            y = 1.0;
        }
        else
        {
            for(i=1; i<abs(a.exp.iexp);++i)
                y *= a.x;
            if(a.exp.iexp < 0)
                y = 1.0/y;
        }
    }
    else
    {
        y = exp(a.exp.fexp * log(a.x));
    }
    return y;
}

