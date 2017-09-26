#include<stdio.h>
#include<stdlib.h>
//double fnAvg(double a, double b);


int main(void)
{
    double x, y, z;
    printf("\nEnter three numbers\n");
    scanf("%lf%lf%lf",&x, &y, &z);

    printf("\nAverage of %g and %g is %g\n", x, y, fnAvg(x,y));
    printf("\nAverage of %g and %g is %g\n", y, z, fnAvg(y,z));
    printf("\nAverage of %g and %g is %g\n", x, z, fnAvg(x,z));

    return 0;
}

double fnAvg(double a, double b)
{
    return (a+b)/2;
}
