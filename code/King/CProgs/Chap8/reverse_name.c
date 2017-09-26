/* reverse_name.c
 *
 * Solution to Programming Project 13 (Chapter 8)
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

#define MAX_LAST_NAME_LEN 20

int main(void)
{
  char first_initial, ch, last_name[MAX_LAST_NAME_LEN];
  int n = 0, i;

  printf("Enter a first and last name: ");

  /* Read first initial */
  scanf(" %c", &first_initial);

  /* Skip remainder of first name */
  while (getchar() != ' ')
    /* empty loop body */ ;

  /* Read last name */
  while (n < MAX_LAST_NAME_LEN && (ch = getchar()) != '\n')
    if (ch != ' ')
      last_name[n++] = ch;

  /* Print name */
  printf("You entered the name: ");
  for (i = 0; i < n; i++)
    putchar(last_name[i]);
  printf(", %c.\n", first_initial);

  return 0;
}
