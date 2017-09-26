		#include<stdio.h>
		int main()
		{
			int a = 10;
			int *iptr = &a;
			void *vptr = iptr;

			printf("\n int* is implicitly convereted to a void*\n");
			return 0;
		}
