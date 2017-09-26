/* reverse2digits.c
 *
 * Solution to Programming Project 1 (Chapter 4)
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
  int n;

  printf("Enter a two-digit number: ");
  scanf("%d", &n);

  printf("The reversal is: %d%d\n", n % 10, n / 10);

  return 0;
}
