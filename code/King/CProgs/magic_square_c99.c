/* magic_square_c99.c
 *
 * Solution to Programming Project 5 (Chapter 9)
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

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
  int n;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");

  printf("Enter size of magic square: ");
  scanf("%d", &n);

  int magic_square[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      magic_square[i][j] = 0;

  create_magic_square(n, magic_square);
  print_magic_square(n, magic_square);

  return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
  int i, row = 0, col = n / 2, old_row, old_col;

  for (i = 1; i <= n * n; i++) {
    if (magic_square[row][col] != 0) {
      row = (old_row + 1) % n;
      col = old_col;
    }

    magic_square[row][col] = i;

    old_row = row;
    old_col = col;

    row = (row > 0 ? row : n) - 1;
    col = (col + 1) % n;
  }
}

void print_magic_square(int n, int magic_square[n][n])
{
  int row, col;

  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++)
      printf("%5d", magic_square[row][col]);
    printf("\n");
  }
}
