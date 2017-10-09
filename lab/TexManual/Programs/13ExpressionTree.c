#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// An expression tree node
struct ExpTree
{
    char value;
    struct ExpTree *lbranch, *rbranch;
};
typedef struct ExpTree* NODEPTR;

bool isOperator(char c);
void inorder(NODEPTR t);
NODEPTR newNode(int v);
NODEPTR constructTree(char postfix[]);
void push(NODEPTR[], NODEPTR, int*);
NODEPTR pop(NODEPTR[], int*);
float evalPost(NODEPTR);

int main()
{
    char postfix[30];
    float fResult;
    printf("\nEnter a postfix expression\n");
    scanf("%s", postfix);
    NODEPTR et = constructTree(postfix);
    printf("infix expression is \n");
    inorder(et);
    printf("\n");
    fResult = evalPost(et);
    printf("\nValue of Postfix Expression is : %g\n\n", fResult);
    return 0;
}

// A utility function to check if 'c' is an operator
bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}
 
// Utility function to do inorder traversal
void inorder(NODEPTR t)
{
    if(t)
    {
        inorder(t-> lbranch);
        printf("%c ", t->value);
        inorder(t->rbranch);
    }
}

NODEPTR newNode(int v)
{
    NODEPTR temp =(NODEPTR) malloc(sizeof(struct ExpTree));
    temp-> lbranch = temp->rbranch = NULL;
    temp->value = v;
    return temp;
}

NODEPTR constructTree(char postfix[])
{
	NODEPTR stack[100];
	int i, top = -1;
    NODEPTR t, t1, t2;
    
    // Traverse through every character of input expression
    for(i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if(!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            push(stack, t, &top);
        }
        else // operator
        {
            t = newNode(postfix[i]);
            // Pop two top nodes
            t1 = pop(stack, &top);      // Remove top
            t2 = pop(stack, &top);
            //  make them children
            t->rbranch = t1;
            t-> lbranch = t2; 
            // Add this subexpression to stack
            push(stack, t, &top);
        }
    } 
    //  only element will be root of expression tree
    t = pop(stack, &top); 
    return t;
}

void push(NODEPTR st[], NODEPTR p, int *t)
{
	*t = *t + 1;
	st[*t] = p;
}

NODEPTR pop(NODEPTR st[], int *t)
{
	NODEPTR temp;
	temp = st[*t];
	*t = *t - 1;
	return temp;
}

float evalPost(NODEPTR root)
{
    float fNum;
    switch(root->value)
	{
        case  '+' : return (evalPost(root->lbranch) + evalPost(root->rbranch));
        case  '-' : return (evalPost(root->lbranch) - evalPost(root->rbranch));
        case  '*' : return (evalPost(root->lbranch) * evalPost(root->rbranch));
        case  '/' : return (evalPost(root->lbranch) / evalPost(root->rbranch));
        case  '^' : return (pow(evalPost(root->lbranch), evalPost(root->rbranch)));
        default:    if(isalpha(root->value))
                    {
                        printf("\n%c = ",root->value);
                        scanf("%f",&fNum);
                        return(fNum);
                    }
                    else
                        return(root->value - '0');
    }
}
