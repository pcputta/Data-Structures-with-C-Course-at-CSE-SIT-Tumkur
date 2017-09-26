/* compute_e2.c
 *
 * Solution to Programming Project 12 (Chapter 6)
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
  float epsilon, e = 0.0f, term = 1.0f;
  int i = 1, fact = 1;

  printf("Enter value for epsilon: ");
  scanf("%f", &epsilon);

  while (term >= epsilon) {
    e += term;
    fact *= i++;
    term = 1.0f / fact;
  }

  printf("Approximation of e: %g\n", e);

  return 0;
}
