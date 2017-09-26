/* scrabble.c
 *
 * Solution to Programming Project 8 (Chapter 13)
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

#define WORD_LEN 15

int compute_scrabble_value(const char *word);

int main(void)
{
  char word[WORD_LEN+1];

  printf("Enter a word: ");
  scanf("%15s", word);

  printf("Scrabble value: %d\n", compute_scrabble_value(word));

  return 0;
}

int compute_scrabble_value(const char *word)
{
  int sum = 0;

  while (*word)
    switch (toupper(*word++)) {
      case 'D': case 'G':
        sum += 2; break;
      case 'B': case 'C': case 'M': case 'P':
        sum += 3; break;
      case 'F': case 'H': case 'V': case 'W': case 'Y':
        sum += 4; break;
      case 'K':
        sum += 5; break;
      case 'J': case 'X':
        sum += 8; break;
      case 'Q': case 'Z':
        sum += 10; break;
      default:
        sum++; break;
    }

  return sum;
}
