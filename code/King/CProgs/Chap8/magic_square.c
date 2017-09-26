/* magic_square.c
 *
 * Solution to Programming Project 17 (Chapter 8)
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
  int size, n, row, col, old_row, old_col, magic_square[99][99] = {{0}};
  /* int size, n, row, col, old_row, old_col; (C99) */

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");

  printf("Enter size of magic square: ");
  scanf("%d", &size);

  /* (C99)
  int magic_square[size][size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      magic_square[i][j] = 0;
  */

  row = 0;
  col = size / 2;
  for (n = 1; n <= size * size; n++) {
    if (magic_square[row][col] != 0) {
      row = (old_row + 1) % size;
      col = old_col;
    }

    magic_square[row][col] = n;

    old_row = row;
    old_col = col;

    row = (row > 0 ? row : size) - 1;
    col = (col + 1) % size;
  }

  for (row = 0; row < size; row++) {
    for (col = 0; col < size; col++)
      printf("%5d", magic_square[row][col]);
    printf("\n");
  }

  return 0;
}
