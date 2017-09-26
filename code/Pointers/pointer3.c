#include<stdio.h>
int main(void)
{
    int i,j;
    int *p;   /* a pointer to an integer */
    printf("%d\n",*p);
    printf("%p %p\n", p, &i);
    p = &i;
    printf("%p %p\n", p, &i);
    return 0;
}

