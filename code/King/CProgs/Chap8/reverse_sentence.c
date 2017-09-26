/* reverse_sentence.c
 *
 * Solution to Programming Project 14 (Chapter 8)
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

#define MAX_SENTENCE_LEN 80

int main(void)
{
  char ch, sentence[MAX_SENTENCE_LEN] = {' '}, terminator = '.';
  int n, i, start, finish;

  printf("Enter a sentence: ");
  for (n = 1; n < MAX_SENTENCE_LEN; n++) {
    ch = getchar();
    if (ch == '.' || ch == '?' || ch == '!') {
      terminator = ch;
      break;
    }
    sentence[n] = ch;
  }

  printf("Reversal of sentence:");
  finish = n;
  for (start = finish - 1; start >= 0; start--) {
    if (sentence[start] == ' ') {
      for (i = start; i < finish; i++)
        putchar(sentence[i]);
      finish = start;
    }
  }
  printf("%c\n", terminator);

  return 0;
}
