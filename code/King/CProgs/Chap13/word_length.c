/* word_length.c
 *
 * Solution to Programming Project 11 (Chapter 13)
 *
 * From C PROGRAMMING: A MODERN APPROACH (Second Edition)
 *
 * Copyright (c) 2008 W. W. Norton & Company
 * All rights reserved.
 *
 * This program may be freely distributed for class use,
 * provided that this copyright notice is retained.
 */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>

#define SENTENCE_LEN 80

double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
  char sentence[SENTENCE_LEN+1];

  printf("Enter a sentence: ");
  read_line(sentence, SENTENCE_LEN);

  printf("Average word length: %.1f\n", compute_average_word_length(sentence));

  return 0;
}

double compute_average_word_length(const char *sentence)
{
  int num_letters = 0, num_words = 0;
  bool in_word = false;
  double average = 0.0;

  while (*sentence)
    if (*sentence++ != ' ') {   /* found a letter */
      num_letters++;
      if (!in_word) {           /* found a new word */
        in_word = true;
        num_words++;
      }
    } else if (in_word)         /* finished a word */
      in_word = false;

  if (num_words > 0)
    average = (double) num_letters / num_words;

  return average;
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
