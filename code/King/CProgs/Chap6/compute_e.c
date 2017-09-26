/* compute_e.c
 *
 * Solution to Programming Project 11 (Chapter 6)
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
  int n, i, fact = 1;
  float e = 1.0f;

  printf("Enter value for n: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    fact *= i;
    e += 1.0f / fact;
  }

  printf("Approximation of e: %g\n", e);

  return 0;
}
