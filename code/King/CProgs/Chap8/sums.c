/* sums.c
 *
 * Solution to Programming Project 7 (Chapter 8)
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

#define N 5

int main(void)
{
  int a[N][N], i, j, sum;

  for (i = 0; i < N; i++) {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < N; j++)
      scanf("%d", &a[i][j]);
  }

  printf("\nRow totals:");
  for (i = 0; i < N; i++) {
    sum = 0;
    for (j = 0; j < N; j++)
      sum += a[i][j];
    printf(" %d", sum);
  }

  printf("\nColumn totals:");
  for (j = 0; j < N; j++) {
    sum = 0;
    for (i = 0; i < N; i++)
      sum += a[i][j];
    printf(" %d", sum);
  }
  printf("\n");

  return 0;
}
