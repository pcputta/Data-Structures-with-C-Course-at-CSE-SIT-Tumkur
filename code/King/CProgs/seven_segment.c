/* seven_segment.c
 *
 * Solution to Programming Project 7 (Chapter 10)
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

#define MAX_DIGITS 10
#define ROWS 3
#define COLS (MAX_DIGITS * 4)

/* external variables */
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},   /* 0 */
                             {0, 1, 1, 0, 0, 0, 0},   /* 1 */
                             {1, 1, 0, 1, 1, 0, 1},   /* 2 */
                             {1, 1, 1, 1, 0, 0, 1},   /* 3 */
                             {0, 1, 1, 0, 0, 1, 1},   /* 4 */
                             {1, 0, 1, 1, 0, 1, 1},   /* 5 */
                             {1, 0, 1, 1, 1, 1, 1},   /* 6 */
                             {1, 1, 1, 0, 0, 0, 0},   /* 7 */
                             {1, 1, 1, 1, 1, 1, 1},   /* 8 */
                             {1, 1, 1, 1, 0, 1, 1}};  /* 9 */
char digits[ROWS][COLS];

/* prototypes */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
  char digit;
  int n = 0;

  clear_digits_array();

  printf("Enter a number: ");
  while (n < MAX_DIGITS) {
    if ((digit = getchar()) == '\n')
      break;
    if (isdigit(digit))
      process_digit(digit - '0', n++);
  }

  print_digits_array();

  return 0;
}

void clear_digits_array(void)
{
  int i, j;

  for (i = 0; i < ROWS; i++)
    for (j = 0; j < COLS; j++)
      digits[i][j] = ' ';
}

void process_digit(int digit, int position)
{
  int offset = COLS / MAX_DIGITS * position;

  if (segments[digit][0]) digits[0][offset + 1] = '_';
  if (segments[digit][1]) digits[1][offset + 2] = '|';
  if (segments[digit][2]) digits[2][offset + 2] = '|';
  if (segments[digit][3]) digits[2][offset + 1] = '_';
  if (segments[digit][4]) digits[2][offset + 0] = '|';
  if (segments[digit][5]) digits[1][offset + 0] = '|';
  if (segments[digit][6]) digits[1][offset + 1] = '_';
}

void print_digits_array(void)
{
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++)
      putchar(digits[i][j]);
    putchar('\n');
  }
}
