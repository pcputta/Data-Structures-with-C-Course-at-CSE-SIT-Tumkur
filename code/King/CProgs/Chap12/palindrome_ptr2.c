/* palindrome_ptr2.c
 *
 * Solution to Programming Project 4 (Chapter 12)
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
  char msg[MAX_MSG_LEN], ch, *p, *q = msg;

  printf("Enter a message: ");
  while (q < msg + MAX_MSG_LEN) {
    if ((ch = getchar()) == '\n')
      break;
    if (isalpha(ch))
      *q++ = toupper(ch);
  }

  for (p = msg, q--; p < q; p++, q--)
    if (*p != *q)
      break;

  if (p >= q)
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}
