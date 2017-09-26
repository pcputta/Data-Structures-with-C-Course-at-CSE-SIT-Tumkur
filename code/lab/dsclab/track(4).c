#include<stdio.h>										/*CPP*/
//#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define MAX 20

float s[MAX];
int Top = 0;

push(float element)
{
	s[++Top] = element;
	return;
}

float pop()
{
	float el;
	el = s[Top--];
	return(el);
}


main()
{
	char postfix[MAX],ch;
	int i,pass =0;
	float op1,op2,res;

	//clrscr();

	printf("\nEnter the Postfix Expression\n");;
	scanf("%s",postfix);
	getchar();

	for(i=0;i<strlen(postfix);i++)
	{

		pass++;
		printf("\nPASS %d",pass);
		printf("\n=============\n");

		ch = postfix[i];
		printf("\nch = %c",ch);

		if(isdigit(ch))
		{
			printf("\nSince %c is an operand push it onto the Stack\n",ch);
			push(ch -'0');
		}
		else
		{
			printf("\nSince %c is an operator pop two operands from the Stack\n",ch,op1,op2);

			op2 = pop();
			op1 = pop();

			printf("OP1 = %f\n",op1);
			printf("OP2 = %f\n",op2);

			printf("\nPerform the operation\n");
			printf("\n\t%f %c %f\n",op1,ch,op2);
			switch(ch)
			{
				case '+' : res = op1 + op2;
					   break;
				case '-' : res = op1 - op2;
					   break;
				case '*' : res = op1 * op2;
					   break;
				case '/' : res = op1 / op2;
					   break;
				case '^' : //res =(int)op1^(int)op2;
					   res =pow(op1,op2);
					   break;
				default : printf("\nInvalid Charecter");
			}
			printf("\nResult of the operation is : %f\n",res);
			printf("Push %f onto the Stack\n",res);
			push(res);
		}
		printf("\n///////////////////////////////////////////////////");
		printf("\nPress any Key\n");
		getchar();
	}
	printf("\nFINAL RESULT");
	printf("\nResult of above expression is : %f\n",pop());
	getchar();
}




/*CPP*/
