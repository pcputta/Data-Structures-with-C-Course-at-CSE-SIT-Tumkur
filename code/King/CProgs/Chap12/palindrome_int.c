/* palindrome_int.c
 *
 * Solution to Programming Project 2(a) (Chapter 12)
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
  char msg[MAX_MSG_LEN], ch;
  int i, n = 0;

  printf("Enter a message: ");
  while (n < MAX_MSG_LEN) {
    if ((ch = getchar()) == '\n')
      break;
    if (isalpha(ch))
      msg[n++] = toupper(ch);
  }

  for (i = 0; i < n / 2; i++)
    if (msg[i] != msg[n - i - 1])
      break;

  if (i == n / 2)
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}
