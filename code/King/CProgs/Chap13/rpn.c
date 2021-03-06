/* rpn.c
 *
 * Solution to Programming Project 15 (Chapter 13)
 *
 * From C PROGRAMMING: A MODERN APPROACH (Second Edition)
 *
 * Copyright (c) 2008 W. W. Norton & Company
 * All rights reserved.
 *
 * This program may be freely distributed for class use,
 * provided that this copyright notice is retained.
 */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define EXPRESSION_LEN 80
#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

/* prototypes */
int evaluate_RPN_expresssion(const char *expression);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
  char expression[EXPRESSION_LEN+1];
  int i = 0;

  printf("Enter an RPN expression: ");
  while (i < EXPRESSION_LEN) {
    scanf(" %c", &expression[i]);
    switch (expression[i++]) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
      case '+': case '-': case '*': case '/':
        break;
      case '=':
        expression[i] = '\0';
        printf("Value of expression: %d\n", evaluate_RPN_expresssion(expression));
        i = 0;
        printf("Enter an RPN expression: ");
        break;
      default:
        exit(EXIT_SUCCESS);
    }
  }

  printf("Invalid expression\n");
  exit(EXIT_FAILURE);
}

int evaluate_RPN_expresssion(const char *expression)
{
  int op1, op2;

  make_empty();
  while (*expression) {
    switch (*expression) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        push(*expression - '0');
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        op1 = pop();
        push(op1 - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        op1 = pop();
        push(op1 / op2);
        break;
      case '=':
        return pop();
      default:
        goto done;
    }
    expression++;
  }

  done:
  printf("Invalid expression\n");
  exit(EXIT_FAILURE);
}

void make_empty(void)
{
  top = 0;
}

bool is_empty(void)
{
  return top == 0;
}

bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(int i)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = i;
}

int pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
  return 0;   /* prevents compiler warning due to stack_underflow call */
}

void stack_overflow(void)
{
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}
