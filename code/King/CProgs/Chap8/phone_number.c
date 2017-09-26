/* phone_number.c
 *
 * Solution to Programming Project 11 (Chapter 8)
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

#define MAX_PHONE_LEN 15

int main(void)
{
  int n = 0, i;
  char ch, phone[MAX_PHONE_LEN];

  printf("Enter phone number: ");
  while ((ch = getchar()) != '\n')
    phone[n++] = ch;

  printf("In numeric form: ");
  for (i = 0; i < n; i++)
    switch (phone[i]) {
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
        putchar(phone[i]);
        break;
    }
  putchar('\n');

  return 0;
}
