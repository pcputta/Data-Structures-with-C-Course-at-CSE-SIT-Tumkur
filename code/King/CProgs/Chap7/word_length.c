/* word_length.c
 *
 * Solution to Programming Project 13 (Chapter 7)
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

int main(void)
{
  char ch;
  int num_letters = 0, num_words = 0;
  bool in_word = false;
  float average = 0.0;

  printf("Enter a sentence: ");
  while ((ch = getchar()) != '\n')
    if (ch != ' ') {     /* found a letter */
      num_letters++;
      if (!in_word) {    /* found a new word */
        in_word = true;
        num_words++;
      }
    } else if (in_word)  /* finished a word */
      in_word = false;

  if (num_words > 0)
    average = (float) num_letters / num_words;
  printf("Average word length: %.1f\n", average);

  return 0;
}
