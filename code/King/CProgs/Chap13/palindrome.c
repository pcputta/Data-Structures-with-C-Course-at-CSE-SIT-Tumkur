/* palindrome.c
 *
 * Solution to Programming Project 17 (Chapter 13)
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
#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <string.h>

#define MSG_LEN 80

bool is_palindrome(const char *message);
int read_line(char str[], int n);

int main(void)
{
  char msg[MSG_LEN+1];

  printf("Enter a message: ");
  read_line(msg, MSG_LEN);

  if (is_palindrome(msg))
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}

bool is_palindrome(const char *message)
{
  char *p = message + strlen(message) - 1;

  while (p > message) {
    while (message < p && !isalpha(*message)) message++;
    while (p > message && !isalpha(*p)) p--;
    if (toupper(*message++) != toupper(*p--))
      return false;
  }

  return true;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
