/* caesar.c
 *
 * Solution to Programming Project 13 (Chapter 13)
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

#define MSG_LEN 80

void encrypt(char *message, int shift);
int read_line(char str[], int n);

int main(void)
{
  char msg[MSG_LEN+1];
  int shift;

  printf("Enter message to be encrypted: ");
  read_line(msg, MSG_LEN);

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  encrypt(msg, shift);
  printf("Encrypted message: %s\n", msg);

  return 0;
}

void encrypt(char *message, int shift)
{
  while (*message) {
    if ('A' <= *message && *message <= 'Z')
      *message = ((*message - 'A') + shift) % 26 + 'A';
    else if ('a' <= *message && *message <= 'z')
      *message = ((*message - 'a') + shift) % 26 + 'a';
    message++;
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
