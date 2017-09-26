#include<stdio.h>
#include<stdlib.h>

void print_count(int n)
{
    printf("T minus %d and counting\n",n);
    sleep(1);
}

int main(void)
{
    int i;

    for(i=10; i>0; --i)
            print_count(i);

    return 0;
}

