/* evaluate.c
 *
 * Solution to Programming Project 12 (Chapter 7)
 *
 * From C PROGRAMMING: A MODERN APPROACH (Second Edition)
 *
 * Copyright (c) 2008 W. W. Norton & Company
 * All rights reserved.
 *
 * This program may be freely distributed for class use,
 * provided that this copyright notice is retained.
 */

#include <stdio.h>

int main(void)
{
  float value, operand;
  char operator;

  printf("Enter an expression: ");

  /* Read first operand */
  scanf("%f ", &value);

  /* Read successive operators and operands */
  while ((operator = getchar()) != '\n') {
    if (operator == ' ')
      continue;
    scanf("%f", &operand);
    switch (operator) {
      case '+': value += operand; break;
      case '-': value -= operand; break;
      case '*': value *= operand; break;
      case '/': value /= operand; break;
    }
  }

  /* Print result */
  printf("Value of expression: %g\n", value);

  return 0;
}
