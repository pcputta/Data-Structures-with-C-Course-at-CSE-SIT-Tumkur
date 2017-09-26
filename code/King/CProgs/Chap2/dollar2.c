/* dollar2.c (alternate solution)
 *
 * Solution to Programming Project 7 (Chapter 2)
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
  int amount, twenties, tens, fives, ones, reduced_amount;

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  twenties = amount / 20;
  reduced_amount = amount - (20 * twenties);

  tens = reduced_amount / 10;
  reduced_amount = reduced_amount - (10 * tens);

  fives = reduced_amount / 5;
  ones = reduced_amount - (5 * fives);

  printf("\n");   /* blank line */

  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf(" $5 bills: %d\n", fives);
  printf(" $1 bills: %d\n", ones);

  return 0;
}
