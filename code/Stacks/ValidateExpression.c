#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STK_SIZE 50

typedef struct{
	char stkArray[STK_SIZE];
	int top;
}STACK_TYPE;

void fnPush(STACK_TYPE*, char);
char fnPop(STACK_TYPE*);

int main()
{
	int i;
	char acExpr[50], cSymb;
	STACK_TYPE expStk;
	expStk.top = -1;
	
	printf("\nEnter an expression\n");
	fgets(acExpr,50,stdin);
	
	fnPush(&expStk,'#');
	
	for(i=0; i<strlen(acExpr);i++)
	{
		cSymb = acExpr[i];
		if(cSymb == '(')
			fnPush(&expStk, cSymb);
		else if (cSymb == ')')
			fnPop(&expStk);
	}
	cSymb = fnPop(&expStk);
	
	if(cSymb == '#')
		printf("\nValid Expression\n");
	else
		printf("\nInvalid Expression\n");
	
	return 0;
}

void fnPush(STACK_TYPE *stk, char c)
{
	stk->top = stk->top + 1;
	stk->stkArray[stk->top] = c;
}

char fnPop(STACK_TYPE *stk)
{
	char c;
	c = stk->stkArray[stk->top];
	stk->top = stk->top - 1;
	return c;
}

