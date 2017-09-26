/* largest.c
 *
 * Solution to Programming Project 1 (Chapter 6)
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
  float x, max = 0.0f;

  for (;;) {
    printf("Enter a number: ");
    scanf("%f", &x);
    if (x <= 0.0f)
      break;
    if (x > max)
      max = x;
  }

  printf("\n");   /* blank line */
  printf("The largest number entered was %g\n", max);

  return 0;
}
