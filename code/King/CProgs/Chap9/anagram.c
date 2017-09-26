/* anagram.c
 *
 * Solution to Programming Project 4 (Chapter 9)
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

#define NUM_LETTERS 26

void read_word(int counts[NUM_LETTERS]);
bool equal_array(int counts1[NUM_LETTERS], int counts2[NUM_LETTERS]);

int main(void)
{
  int counts1[NUM_LETTERS] = {0}, counts2[NUM_LETTERS] = {0};

  printf("Enter first word: ");
  read_word(counts1);
  printf("Enter second word: ");
  read_word(counts2);

  if (equal_array(counts1, counts2))
    printf("The words are anagrams.\n");
  else
    printf("The words are not anagrams.\n");

  return 0;
}

void read_word(int counts[NUM_LETTERS])
{
  char ch;

  while ((ch = getchar()) != '\n')
    if (isalpha(ch))
      counts[tolower(ch) - 'a']++;
}

bool equal_array(int counts1[NUM_LETTERS], int counts2[NUM_LETTERS])
{
  int i;

  for (i = 0; i < NUM_LETTERS; i++)
    if (counts1[i] != counts2[i])
      return false;

  return true;
}
