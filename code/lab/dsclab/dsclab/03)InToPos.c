#include<stdio.h>									/*CPP*/
#include<ctype.h>
#include<stdlib.h>
#define MAX 20

char s[MAX];
int Top = 0;


int precd(char elem);
void push(char elem);
int pop();
main()
{
	char infix[MAX],postfix[MAX],ch,elem;
	int i = 0, j = 0;

	//clrscr();

	printf("\nProgram to Convert Infix to Postfix Expression");
	printf("\n\n");
	printf("\nEnter the Infix Expression : \n");
	scanf("%s",infix);

	push('#');				/*initially push # onto stack */

	for(i=0;i<strlen(infix);i++)
	{
		ch = infix[i];
		if(isalnum(ch))
			postfix[j++] = ch;
		else
			if(ch == '(')
				push(ch);
			else
			if(ch == ')')
			{
				while(s[Top] != '(')
					postfix[j++] = pop();
				elem = pop();
			}
			else
			{
				while(precd(s[Top]) >= precd(ch))
					postfix[j++] = pop();

				push(ch);
			}
	}
	while(s[Top] != '#')
		postfix[j++] = pop();
	postfix[j] = '\0';
	printf("\nResultant Postfix Expression is : \n%s\n",postfix);
	//getch();
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
