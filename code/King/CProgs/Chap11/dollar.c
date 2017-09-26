/* dollar.c
 *
 * Solution to Programming Project 1 (Chapter 11)
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

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
  int amount, twenties, tens, fives, ones;

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  pay_amount(amount, &twenties, &tens, &fives, &ones);

  printf("\n");   /* blank line */

  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf(" $5 bills: %d\n", fives);
  printf(" $1 bills: %d\n", ones);

  return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
  *twenties = dollars / 20;
  dollars -= *twenties * 20;

  *tens = dollars / 10;
  dollars -= *tens * 10;

  *fives = dollars / 5;
  *ones = dollars % 5;
}
