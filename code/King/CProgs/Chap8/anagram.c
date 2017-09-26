/* anagram.c
 *
 * Solution to Programming Project 16 (Chapter 8)
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

#define NUM_LETTERS 26

int main(void)
{
  int i = 0, letter_count[NUM_LETTERS] = {0};
  char ch;

  printf("Enter first word: ");
  while ((ch = getchar()) != '\n')
    if (isalpha(ch))
      letter_count[tolower(ch) - 'a']++;

  printf("Enter second word: ");
  while ((ch = getchar()) != '\n')
    if (isalpha(ch))
      letter_count[tolower(ch) - 'a']--;

  while (i < NUM_LETTERS && letter_count[i] == 0)
    i++;

  if (i == NUM_LETTERS)
    printf("The words are anagrams.\n");
  else
    printf("The words are not anagrams.\n");

  return 0;
}
