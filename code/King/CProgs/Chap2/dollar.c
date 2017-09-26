/* dollar.c
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
  int amount, num_twenties, num_tens, num_fives, num_ones,
      amount_reduced_by_twenties, amount_reduced_by_tens;

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  num_twenties = amount / 20;
  amount_reduced_by_twenties = amount - (20 * num_twenties);

  num_tens = amount_reduced_by_twenties / 10;
  amount_reduced_by_tens = amount_reduced_by_twenties - (10 * num_tens);

  num_fives = amount_reduced_by_tens / 5;
  num_ones = amount_reduced_by_tens - (5 * num_fives);

  printf("\n");   /* blank line */

  printf("$20 bills: %d\n", num_twenties);
  printf("$10 bills: %d\n", num_tens);
  printf(" $5 bills: %d\n", num_fives);
  printf(" $1 bills: %d\n", num_ones);

  return 0;
}
