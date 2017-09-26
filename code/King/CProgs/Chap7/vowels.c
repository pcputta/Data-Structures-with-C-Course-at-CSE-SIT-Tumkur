/* vowels.c
 *
 * Solution to Programming Project 10 (Chapter 7)
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

int main(void)
{
  char ch;
  int num_vowels = 0;

  printf("Enter a sentence: ");
  while ((ch = getchar()) != '\n')
    switch (toupper(ch)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        num_vowels++;
    }

  printf("Your sentence contains %d vowels.\n", num_vowels);

  return 0;
}
