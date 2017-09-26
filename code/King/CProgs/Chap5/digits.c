/* digits.c
 *
 * Solution to Programming Project 1 (Chapter 5)
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

/* Note: Program assumes that user enters a nonnegative integer. */

int main(void)
{
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  if (n < 10)
    printf("The number %d has 1 digit\n", n);
  else if (n < 100)
    printf("The number %d has 2 digits\n", n);
  else if (n < 1000)
    printf("The number %d has 3 digits\n", n);
  else
    printf("The number %d has 4 digits\n", n);

  return 0;
}
