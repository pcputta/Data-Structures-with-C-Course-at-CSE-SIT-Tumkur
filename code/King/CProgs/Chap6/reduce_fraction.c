/* reduce_fraction.c
 *
 * Solution to Programming Project 3 (Chapter 6)
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
  int num, denom, m, n, remainder;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &denom);

  /* Compute GCD (see Programming Project 2) */
  m = num; n = denom;
  while (n != 0) {
    remainder = m % n;
    m = n;
    n = remainder;
  }

  /* Divide both numerator and denominator by GCD */
  num /= m;
  denom /= m;

  /* Ensure that denominator is positive */
  if (denom < 0) {
    num *= -1;
    denom *= -1;
  }

  printf("In lowest terms: %d/%d\n", num, denom);

  return 0;
}

