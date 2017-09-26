/* sum3.c
 *
 * Solution to Programming Project 3 (Chapter 7)
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
  double d, sum = 0;

  printf("This program sums a series of double values.\n");
  printf("Enter values (0 to terminate): ");

  scanf("%lf", &d);
  while (d != 0) {
    sum += d;
    scanf("%lf", &d);
  }
  printf("The sum is: %g\n", sum);

  return 0;
}
