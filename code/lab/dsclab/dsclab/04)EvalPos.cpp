#include<stdio.h>										/*CPP*/
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define MAX 20

int s[MAX];
int Top = 0;

void push(int element)
{
	s[++Top] = element;
	return;
}

int pop()
{
        int el;
        el = s[Top--];
        return(el);
}


main()
{
        char postfix[MAX],ch;
        int i,op1,op2,res;

  	//clrscr();

        printf("\nEnter the Postfix Expression\n");;
        scanf("%s",postfix);

        for(i=0;i<strlen(postfix);i++)
        {
                ch = postfix[i];
                if(isdigit(ch))
                        push(ch -'0');
                else
                {
                        op2 = pop();
                        op1 = pop();
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
                                case '^' : res = (int)(pow(op1,op2));
                                           break;
                                default : printf("\nInvalid Charecter");
                        }
                        push(res);
                }
        }
        printf("\nResult of above expression is : %d\n",pop());
        //getch();
}




/*CPP*/
