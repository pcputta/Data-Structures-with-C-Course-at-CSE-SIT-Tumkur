/* caesar.c
 *
 * Solution to Programming Project 15 (Chapter 8)
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

#define MAX_MSG_LEN 80

int main(void)
{
  char ch, msg[MAX_MSG_LEN];
  int n = 0, i, shift;

  printf("Enter message to be encrypted: ");
  while ((ch = getchar()) != '\n')
    msg[n++] = ch;

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  for (i = 0; i < n; i++)
    if ('A' <= msg[i] && msg[i] <= 'Z')
      msg[i] = ((msg[i] - 'A') + shift) % 26 + 'A';
    else if ('a' <= msg[i] && msg[i] <= 'z')
      msg[i] = ((msg[i] - 'a') + shift) % 26 + 'a';

  printf("Encrypted message: ");
  for (i = 0; i < n; i++)
    putchar(msg[i]);
  printf("\n");

  return 0;
}
