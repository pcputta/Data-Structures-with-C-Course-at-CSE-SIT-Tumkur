#include <stdio.h>
#include <stdlib.h>

/*typedef struct{*/
/*	char c;*/
/*	double d;*/
/*	int i;*/
/*}mytype_t;*/

typedef struct{
	double d;
	int i;
	char c;	
}mytype_t;

int main()
{
	mytype_t val[2];
	printf("\nSize of mytype_t is %lu units\n", sizeof(mytype_t));
	
	printf("\nSize of int is %lu units\n", sizeof(int));
	printf("\nSize of char is %lu units\n", sizeof(char));
	printf("\nSize of double is %lu units\n", sizeof(double));
	
	printf("\nAddress of val[0] variable is : %u\n", &val[0]);
	printf("\nAddress of integer member is : %u\n", &val[0].i);
	printf("\nAddress of double member is : %u\n", &val[0].d);
	printf("\nAddress of character member is : %u\n", &val[0].c);

	printf("\nAddress of val[1] variable is : %u\n", &val[1]);
    return 0;
}

