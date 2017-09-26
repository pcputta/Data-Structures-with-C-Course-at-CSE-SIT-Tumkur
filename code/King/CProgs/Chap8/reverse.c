/* reverse.c
 *
 * Solution to Programming Project 4 (Chapter 8)
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

#define SIZE ((int) (sizeof(a) / sizeof(a[0])))

int main(void)
{
  int a[10], i;

  printf("Enter %d numbers: ", SIZE);
  for (i = 0; i < SIZE; i++)
    scanf("%d", &a[i]);

  printf("In reverse order:");
  for (i = SIZE - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}
