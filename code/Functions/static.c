		#include<stdio.h>

		int iVal = 9;

		void fnDoSomething(void);

		int main(void)
		{
			auto int j, iVal;
			

			for(j=0;j<5;j++)
				fnDoSomething();

			return 0;
		}

		void fnDoSomething(void)
		{
			static int i=0;
			i++;
			printf("\ni = %d\n", i);
		}






	
