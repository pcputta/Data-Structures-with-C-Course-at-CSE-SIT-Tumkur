/* phone_number.c
 *
 * Solution to Programming Project 4 (Chapter 7)
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
  char ch;

  printf("Enter phone number: ");
  while ((ch = getchar()) != '\n')
    switch (ch) {
      case 'A': case 'B': case 'C':
        putchar('2');
        break;
      case 'D': case 'E': case 'F':
        putchar('3');
        break;
      case 'G': case 'H': case 'I':
        putchar('4');
        break;
      case 'J': case 'K': case 'L':
        putchar('5');
        break;
      case 'M': case 'N': case 'O':
        putchar('6');
        break;
      case 'P': case 'R': case 'S':
        putchar('7');
        break;
      case 'T': case 'U': case 'V':
        putchar('8');
        break;
      case 'W': case 'X': case 'Y':
        putchar('9');
        break;
      default:
        putchar(ch);
        break;
    }
  putchar('\n');

  return 0;
}
