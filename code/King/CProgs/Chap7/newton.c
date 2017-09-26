/* newton.c
 *
 * Solution to Programming Project 14 (Chapter 7)
 *
 * From C PROGRAMMING: A MODERN APPROACH (Second Edition)
 *
 * Copyright (c) 2008 W. W. Norton & Company
 * All rights reserved.
 *
 * This program may be freely distributed for class use,
 * provided that this copyright notice is retained.
 */

#include <math.h>
#include <stdio.h>

#define TOLERANCE 0.00001

int main(void)
{
  double x, y_old = 1.0, y_new, error;

  printf("Enter a positive number: ");
  scanf("%lf", &x);

  do {
    y_new = (y_old + (x / y_old)) / 2.0;
    error = fabs((y_new - y_old) / y_new);
    y_old = y_new;
  } while (error >= TOLERANCE);

  printf("Square root: %g\n", y_new);

  return 0;
}
