	#include <stdio.h>

	int main(void)
	{
	    int i,j;
	    int *p = NULL;   /* a pointer to an integer */ //datatype *ptr_name;
	    p = &i;
	    *p=5;
	    j=i;
	    printf("%d %d %d\n", i, j, *p);
//	    printf("%d %d %d\n", i, j, *(&i));
	    return 0;
	}

/* Ignore
struct something
{
	int a, b;
	float f;
};

typedef struct something OBJECT;

OBJECT ob1;
OBJECT *objpointer;

objpointer = &ob1;

ob1.a;
objpointer->a;

*/

