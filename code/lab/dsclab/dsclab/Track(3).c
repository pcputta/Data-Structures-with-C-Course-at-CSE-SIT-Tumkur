#include<stdio.h>									/*CPP*/
#include<ctype.h>
#include<stdlib.h>
#define MAX 50

char s[MAX];
int Top = 0;


void push(char elem);
int precd(char elem);
int pop();

main()
{
	char infix[MAX],postfix[MAX],ch,elem;
	int i = 0, j = 0,z = 0,pass = 0,f;

	//clrscr();

	printf("\nProgram to Convert Infix to Postfix Expression");
	printf("\n\n");
	printf("\nEnter the Infix Expression : \n");
	scanf("%s",infix);

	push('#');				/*initially push # onto stack */

	for(i=0;i<strlen(infix);i++)
	{

		pass++;
		printf("\nPASS %d",pass);
		printf("\n=============\n");
		ch = infix[i];
		printf("\nch = %c",ch);
		if(isalnum(ch))
		{
			postfix[j++] = ch;
			printf("\nSince %c is character assign to postfix string\n",ch);
			printf("//////////////////////////////////////////////////////////////");
			printf("\nThe Postfix string now is : ");
			for(f=0;f<j;f++)
				printf("%c",postfix[f]);
			printf("\n//////////////////////////////////////////////////////////////\n");

		}
		else
			if(ch == '(')
			{
				push(ch);
				printf("\nEncountered character is an left parantheses push it onto the stack\n");
			}
			else
			if(ch == ')')
			{
				printf("\nEncountered character is an right parantheses\nPerform pop operation on stack until you encounter a left parantheses\n");
				while(s[Top] != '(')
				{

					postfix[j++] = pop();
					printf("\n%c is appended to the postfix string\n",postfix[j-1]);
					printf("//////////////////////////////////////////////////////////////");
					printf("\nThe Postfix string now is : ");
					for(f=0;f<j;f++)
						printf("%c",postfix[f]);
					printf("\n///////// /////////////////////////////////////////////////////\n");
					getchar();

				}
				elem = pop();
				printf("\nPop out left parantheses\n");
			}
			else
			{
				printf("\nEncountered Charecter is an Operator so Check for its precedence\n");

				while(precd(s[Top]) >= precd(ch))
				{
					printf("\nPrecedence of %c is greater than the encountered operator %c\n",s[Top],ch);
					printf("\nSo pop it and append it to the postfix expression\n");
					postfix[j++] = pop();
					printf("//////////////////////////////////////////////////////////////");
					printf("\nThe Postfix string now is : ");
					for(f=0;f<j;f++)
						printf("%c",postfix[f]);
					printf("\n/////////////////////////s/////////////////////////////////////\n");
					getchar();

				}


				printf("\nPrecedence of %c is lesser than the encounterd operator %c\n",s[Top],ch);
				printf("\nSo push the encountered operator %c onto the stack\n",ch);
				push(ch);

			}
			printf("--------------------------------------------------------------------");

			printf("\nPress any key\n");
			getchar();
	}
	while(s[Top] != '#')
	{
		if(z==0)
		{
			z++;
			printf("\nThere are Still operators remaining in the Stack\n");
			printf("Pop them and assign them to the Postfix String\n");
		}

		postfix[j++] = pop();
		printf("\nRemove %c from Stack and assign it to the Postfix String\n",postfix[j-1]);
		printf("//////////////////////////////////////////////////////////////");
		printf("\nThe Postfix string now is : ");
		for(f=0;f<j;f++)
			printf("%c",postfix[f]);
		printf("\n//////////////////////////////////////////////////////////////\n");
		printf("--------------------------------------------------------------------");
		printf("\nPress any key\n");
		getchar();
	}
	postfix[j] = '\0';
	printf("\n=========================================\n");
	printf("\nResultant Postfix Expression is : %s\n",postfix);
	printf("\n=========================================\n");
	getchar();
}


/*Function to Push Character*/

void push(char elem)
{
	++Top;
	s[Top] = elem;
	return;
}


/*Function to Pop a Character*/

int pop()
{

	char elem;
	elem = s[Top];
	--Top;
	return (elem);
}


/*Function to return Precedence*/

int precd(char elem)
{
	switch(elem)
	{
		case '+' :
		case '-' : return 1;

		case '*' :
		case '/' : return 2;

		case '^' :
		case '$' : return 3;

		case '(' :
		case '#' : return 0;
	}

}


/*CPP*/
