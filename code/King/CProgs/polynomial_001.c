/* polynomial.c
 *
 * Solution to Programming Project 6 (Chapter 9)
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

double f(double x);

int main(void)
{
  double x;

  printf("Enter value for x: ");
  scanf("%lf", &x);

  printf("Polynomial value: %g\n", f(x));

  return 0;
}

double f(double x)
{
  return ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
}
