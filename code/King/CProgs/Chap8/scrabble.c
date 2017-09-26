/* scrabble.c
 *
 * Solution to Programming Project 12 (Chapter 8)
 *
 * From C PROGRAMMING: A MODERN APPROACH (Second Edition)
 *
 * Copyright (c) 2008 W. W. Norton & Company
 * All rights reserved.
 *
 * This program may be freely distributed for class use,
 * provided that this copyright notice is retained.
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
  int values[] = {1, 3, 3,  2, 1, 4, 2, 4, 1, 8, 5, 1,  3,
                  1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  int sum = 0;
  char ch;

  printf("Enter a word: ");
  while ((ch = getchar()) != '\n')
    sum += values[toupper(ch) - 'A'];

  printf("Scrabble value: %d\n", sum);

  return 0;
}
