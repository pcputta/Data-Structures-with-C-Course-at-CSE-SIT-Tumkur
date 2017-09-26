/* vowels.c
 *
 * Solution to Programming Project 9 (Chapter 13)
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

#define SENTENCE_LEN 80

int compute_vowel_count(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
  char sentence[SENTENCE_LEN+1];

  printf("Enter a sentence: ");
  read_line(sentence, SENTENCE_LEN);

  printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

  return 0;
}

int compute_vowel_count(const char *sentence)
{
  int num_vowels = 0;

  while (*sentence)
    switch (toupper(*sentence++)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        num_vowels++;
    }

  return num_vowels;
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
