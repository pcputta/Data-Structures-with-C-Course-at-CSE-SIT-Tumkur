/* b1ff.c
 *
 * Solution to Programming Project 6 (Chapter 8)
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

#define MAX_MSG_LEN 80

int main(void)
{
  char ch, msg[MAX_MSG_LEN];
  int i, n;

  printf("Enter message: ");
  for (n = 0; n < MAX_MSG_LEN; n++) {
    if ((ch = getchar()) == '\n')
      break;
    msg[n] = toupper(ch);
  }

  printf("In B1FF-speak: ");
  for (i = 0; i < n; i++)
    switch (msg[i]) {
      case 'A':  putchar('4');
                 break;
      case 'B':  putchar('8');
                 break;
      case 'E':  putchar('3');
                 break;
      case 'I':  putchar('1');
                 break;
      case 'O':  putchar('0');
                 break;
      case 'S':  putchar('5');
                 break;
      default:   putchar(msg[i]);
    }
  printf("!!!!!!!!!!\n");

  return 0;
}
