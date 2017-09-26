/* anagram.c
 *
 * Solution to Programming Project 14 (Chapter 13)
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
#include <stdbool.h>  /* C99 only */
#include <stdio.h>

#define WORD_LEN 30
#define NUM_LETTERS 26

bool are_anagrams(const char *word1, const char *word2);
void process_word(const char *word, int counts[NUM_LETTERS], int increment);
int read_line(char str[], int n);

int main(void)
{
  char word1[WORD_LEN+1], word2[WORD_LEN+1];

  printf("Enter first word: ");
  read_line(word1, WORD_LEN);
  printf("Enter second word: ");
  read_line(word2, WORD_LEN);

  if (are_anagrams(word1, word2))
    printf("The words are anagrams\n");
  else
    printf("The words are not anagrams\n");

  return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
  int i, counts[NUM_LETTERS] = {0};

  process_word(word1, counts, 1);
  process_word(word2, counts, -1);

  for (i = 0; i < NUM_LETTERS; i++)
    if (counts[i] != 0)
      return false;

  return true;
}

void process_word(const char *word, int counts[NUM_LETTERS], int increment)
{
  while (*word) {
    if (isalpha(*word))
      counts[tolower(*word) - 'a'] += increment;
    word++;
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
