/* reverse_message.c
 *
 * Solution to Programming Project 16 (Chapter 13)
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
#include <string.h>

#define MSG_LEN 80   /* maximum length of message */

void reverse(char *message);
int read_line(char str[], int n);

int main(void)
{
  char msg[MSG_LEN+1];

  printf("Enter a message: ");
  read_line(msg, MSG_LEN);

  reverse(msg);
  printf("Reversal is: %s\n", msg);

  return 0;
}

void reverse(char *message)
{
  char temp, *p = message + strlen(message) - 1;

  while (p > message) {
    temp = *message;
    *message++ = *p;
    *p-- = temp;
  }
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
