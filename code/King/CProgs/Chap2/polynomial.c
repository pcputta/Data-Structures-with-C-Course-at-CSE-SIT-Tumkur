/* polynomial.c
 *
 * Solution to Programming Project 5 (Chapter 2)
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
  float x, y;

  printf("Enter value for x: ");
  scanf("%f", &x);

  y = (3.0f * x * x * x * x * x) + (2.0f * x * x * x * x) - (5.0f * x * x * x) -
      (x * x) + (7.0f * x) - 6.0f;

  printf("Polynomial value: %.2f\n", y);

  return 0;
}
