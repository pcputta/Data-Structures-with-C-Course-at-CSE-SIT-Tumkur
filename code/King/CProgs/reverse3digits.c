/* reverse3digits.c
 *
 * Solution to Programming Project 3 (Chapter 4)
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
  int d1, d2, d3;

  printf("Enter a three-digit number: ");
  scanf("%1d%1d%1d", &d1, &d2, &d3);

  printf("The reversal is: %d%d%d\n", d3, d2, d1);

  return 0;
}
