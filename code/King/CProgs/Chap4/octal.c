/* octal.c
 *
 * Solution to Programming Project 4 (Chapter 4)
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
  int n, d1, d2, d3, d4, d5;

  printf("Enter a number between 0 and 32767: ");
  scanf("%d", &n);

  d5 = n % 8;
  n /= 8;
  d4 = n % 8;
  n /= 8;
  d3 = n % 8;
  n /= 8;
  d2 = n % 8;
  d1 = n / 8;

  printf("In octal, your number is: %d%d%d%d%d\n", d1, d2, d3, d4, d5);

  return 0;
}
