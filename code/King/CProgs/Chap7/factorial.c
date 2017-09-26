/* factorial.c
 *
 * Solution to Programming Project 15 (Chapter 7)
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
  int i, n;
  short s_fact = 1;
  int i_fact = 1;
  long l_fact = 1;
  long long ll_fact = 1;   /* C99 only */
  float f_fact = 1;
  double d_fact = 1;
  long double ld_fact = 1;

  printf("Enter a positive integer: ");
  scanf("%d", &n);

  for (i = 2; i <= n; i++) {
    s_fact *= i;
    i_fact *= i;
    l_fact *= i;
    ll_fact *= i;   /* C99 only */
    f_fact *= i;
    d_fact *= i;
    ld_fact *= i;
  }

  printf("Factorial of %d (short)      : %hd\n", n, s_fact);
  printf("Factorial of %d (int)        : %d\n", n, i_fact);
  printf("Factorial of %d (long)       : %ld\n", n, l_fact);
  printf("Factorial of %d (long long)  : %lld\n", n, ll_fact);   /* C99 only */
  printf("Factorial of %d (float)      : %f\n", n, f_fact);
  printf("Factorial of %d (double)     : %f\n", n, d_fact);
  printf("Factorial of %d (long double): %Lf\n", n, ld_fact);

  return 0;
}

/* Largest value of n for which program correctly prints factorial of n:
 *
 * Type           n
 * ----          --
 * short          7
 * int           12
 * long          12
 * long long     20
 * float         13
 * double        22
 * long double   25
 *
 * Results may vary, but values shown are typical for 32-bit machines.
 */
