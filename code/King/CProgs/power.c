/* power.c
 *
 * Solution to Programming Project 7 (Chapter 9)
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

int power(int x, int n);

int main(void)
{
  int x, n;

  printf("Enter value for x: ");
  scanf("%d", &x);
  printf("Enter value for n: ");
  scanf("%d", &n);

  printf("x raised to the power n: %d\n", power(x, n));

  return 0;
}

int power(int x, int n)
{
  if (n == 0)
    return 1;
  else if (n % 2 == 1)          /* n is odd */
    return x * power(x, n - 1);
  else {                        /* n is even */
    int y = power(x, n / 2);
    return y * y;
  }
}
