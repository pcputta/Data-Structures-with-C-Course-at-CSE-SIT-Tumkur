/* random_walk.c
 *
 * Solution to Programming Project 9 (Chapter 8)
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
#include <stdlib.h>
#include <time.h>

#define N 10
#define FILLER '.'

int main(void)
{
  char a[N][N], letter = 'A';
  int x, y, direction, moves_tried, new_x, new_y;

  for (x = 0; x < N; x++)
    for (y = 0; y < N; y++)
      a[x][y] = FILLER;

  srand((unsigned) time(NULL));

  x = 0;
  y = 0;
  a[x][y] = letter++;
  direction = rand() % 4;
  moves_tried = 0;

  while (moves_tried < 4 && letter <= 'Z') {
    switch ((direction + moves_tried) % 4) {
      case 0: new_x = x; new_y = y + 1; break;
      case 1: new_x = x; new_y = y - 1; break;
      case 2: new_x = x + 1; new_y = y; break;
      case 3: new_x = x - 1; new_y = y; break;
    }
    if (0 <= new_x && new_x < N &&
        0 <= new_y && new_y < N &&
        a[new_x][new_y] == FILLER) {
      x = new_x;
      y = new_y;
      a[x][y] = letter++;
      direction = rand() % 4;
      moves_tried = 0;
    } else
      moves_tried++;
  }

  for (x = 0; x < N; x++) {
    for (y = 0; y < N; y++)
      printf("%c ", a[x][y]);
    printf("\n");
  }

  return 0;
}
