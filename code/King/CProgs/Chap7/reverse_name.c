/* reverse_name.c
 *
 * Solution to Programming Project 11 (Chapter 7)
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
  char first_initial, ch;

  printf("Enter a first and last name: ");

  /* Read first initial */
  scanf(" %c", &first_initial);

  /* Skip remainder of first name */
  while (getchar() != ' ')
    /* empty loop body */ ;

  /* Read and print last name */
  while ((ch = getchar()) != '\n')
    if (ch != ' ')
      putchar(ch);

  /* Print first initial */
  printf(", %c.\n", first_initial);

  return 0;
}
