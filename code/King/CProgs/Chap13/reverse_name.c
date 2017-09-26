/* reverse_name.c
 *
 * Solution to Programming Project 10 (Chapter 13)
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

#define NAME_LEN 30

void reverse_name(char *name);
int read_line(char str[], int n);

int main(void)
{
  char name[NAME_LEN+1];

  printf("Enter a first and last name: ");
  read_line(name, NAME_LEN);

  reverse_name(name);
  printf("%s\n", name);

  return 0;
}

void reverse_name(char *name)
{
  char fi[5];   /* string containing first initial and other formatting */
  char *p = name;

  /* Find first initial and create first-initial string */
  while (*p == ' ') p++;
  sprintf(fi, ", %c.", *p);

  /* Find last name */
  while (*p != ' ') p++;
  while (*p == ' ') p++;

  /* Move last name to beginning of 'name' string */
  while (*p != ' ' && *p != '\0')
    *name++ = *p++;

  /* Append first-initial string */
  strcpy(name, fi);
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
