/* reverse_sentence.c
 *
 * Solution to Programming Project 12 (Chapter 13)
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

#define NUM_WORDS 30
#define WORD_LEN 20

int main(void)
{
  char ch, words[NUM_WORDS][WORD_LEN+1], terminator = '.';
  int n = 0, i = 0;

  printf("Enter a sentence: ");
  while (n < NUM_WORDS)
    switch (ch = getchar()) {
      case ' ':
        if (i > 0) {
          words[n++][i] = '\0';
          i = 0;
        }
        break;
      case '.': case '?': case '!':
        if (i > 0)
          words[n++][i] = '\0';
        terminator = ch;
        goto done;
      default:
        words[n][i++] = ch;
    }

  done:
  printf("Reversal of sentence:");
  for (i = n - 1; i >= 0; i--)
    printf(" %s", words[i]);
  printf("%c\n", terminator);

  return 0;
}
