/* square3.c
 *
 * Solution to Programming Project 7 (Chapter 6)
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
  int i, n, odd, square;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  odd = 3;
  square = 1;
  for (i = 1; i <= n; i++) {
    printf("%10d%10d\n", i, square);
    square += odd;
    odd += 2;
  }

  return 0;
}
