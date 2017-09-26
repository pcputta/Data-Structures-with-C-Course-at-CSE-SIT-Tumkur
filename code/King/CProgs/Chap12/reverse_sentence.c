/* reverse_sentence.c
 *
 * Solution to Programming Project 5 (Chapter 12)
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
  char ch, sentence[MAX_SENTENCE_LEN + 1] = {' '}, terminator = '.',
       *start, *finish = sentence + 1, *p = sentence;

  printf("Enter a sentence: ");
  while (finish <= sentence + MAX_SENTENCE_LEN) {
    ch = getchar();
    if (ch == '.' || ch == '?' || ch == '!') {
      terminator = ch;
      break;
    }
    *finish++ = ch;
  }

  printf("Reversal of sentence:");
  for (start = (finish - 1); start >= sentence; start--) {
    if (*start == ' ') {
      for (p = start; p < finish; p++)
        putchar(*p);
      finish = start;
    }
  }
  printf("%c\n", terminator);

  return 0;
}
