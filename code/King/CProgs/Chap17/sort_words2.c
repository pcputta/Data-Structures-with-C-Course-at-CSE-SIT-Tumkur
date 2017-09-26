/* sort_words2.c
 *
 * Solution to Programming Project 6 (Chapter 17)
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
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define WORD_LEN 20

int read_line(char str[], int n);
int compare_strings(const void *p, const void *q);

int main(void)
{
  char *words[MAX_WORDS], word[WORD_LEN+1];
  int i, num_words = 0;

  for (;;) {
    if (num_words == MAX_WORDS) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter word: ");
    read_line(word, WORD_LEN);
    if (strlen(word) == 0)
      break;

    words[num_words] = malloc(strlen(word) + 1);
    if (words[num_words] == NULL) {
      printf("-- No space left --\n");
      break;
    }

    strcpy(words[num_words], word);
    num_words++;
  }

  qsort(words, num_words, sizeof(char *), compare_strings);

  printf("\nIn sorted order:");
  for (i = 0; i < num_words; i++)
    printf(" %s", words[i]);
  printf("\n");

  return 0;
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

int compare_strings(const void *p, const void *q)
{
  return strcmp(*(char **)p, *(char **)q);
}
