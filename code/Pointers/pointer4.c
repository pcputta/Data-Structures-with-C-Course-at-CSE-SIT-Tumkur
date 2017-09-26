#include<stdio.h>
int main(void)
{
    int i;
    int *p;   /* a pointer to an integer */
    p = &i;
    *p=5;
    printf("%d %d\n", i, *p);
    return 0;
}

//see image 6
