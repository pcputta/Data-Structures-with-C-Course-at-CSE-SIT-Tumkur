/* reverse_digits.c
 *
 * Solution to Programming Project 5 (Chapter 6)
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
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  printf("The reversal is: ");

  do {
    printf("%d", n % 10);
    n /= 10;
  } while (n > 0);

  printf("\n");

  return 0;
}
