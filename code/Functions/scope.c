		#include<stdio.h>

		int iVal = 9;

		void fnDoSomething(void);

		int main(void)
		{
			int i, iVal;
			i= 3;
			iVal = 5;

			printf("\ni = %d\n iVal = %d\n", i, iVal);
			fnDoSomething();

			return 0;
		}

		void fnDoSomething(void)
		{
			int i;
			i = 7;
			printf("\ni = %d\n iVal = %d\n", i, iVal);
		}






	
