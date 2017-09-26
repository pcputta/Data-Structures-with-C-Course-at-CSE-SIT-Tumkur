/* fraction_math.c
 *
 * Solution to Programming Project 7 (Chapter 7)
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
  int num1, denom1, num2, denom2, result_num, result_denom;
  char operator;

  printf("Enter two fractions separated by a +, -, * or / sign: ");
  scanf("%d/%d %c%d/%d", &num1, &denom1, &operator, &num2, &denom2);

  switch (operator) {
    case '+':
      result_num = num1 * denom2 + num2 * denom1;
      result_denom = denom1 * denom2;
      printf("The sum is %d/%d\n", result_num, result_denom);
      break;
    case '-':
      result_num = num1 * denom2 - num2 * denom1;
      result_denom = denom1 * denom2;
      printf("The difference is %d/%d\n", result_num, result_denom);
      break;
    case '*':
      result_num = num1 * num2;
      result_denom = denom1 * denom2;
      printf("The product is %d/%d\n", result_num, result_denom);
      break;
    case '/':
      result_num = num1 * denom2;
      result_denom = denom1 * num2;
      printf("The quotient is %d/%d\n", result_num, result_denom);
      break;
    default:
      printf("Unrecognized operator: %c\n", operator);
  }

  return 0;
}
