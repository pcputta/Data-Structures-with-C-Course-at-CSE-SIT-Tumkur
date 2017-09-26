/* reduce_fraction.c
 *
 * Solution to Programming Project 3 (Chapter 11)
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

int find_gcd(int m, int n);
void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator);

int main(void)
{
  int num, denom;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &denom);

  reduce(num, denom, &num, &denom);
  printf("In lowest terms: %d/%d\n", num, denom);

  return 0;
}

int find_gcd(int m, int n)
{
  while (n != 0) {
    int remainder = m % n;
    m = n;
    n = remainder;
  }
  return m;
}

void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator)
{
  int gcd = find_gcd(numerator, denominator);

  /* Divide both numerator and denominator by GCD */
  *reduced_numerator = numerator / gcd;
  *reduced_denominator = denominator / gcd;

  /* Ensure that denominator is positive */
  if (*reduced_denominator < 0) {
    *reduced_numerator *= -1;
    *reduced_denominator *= -1;
  }
}
