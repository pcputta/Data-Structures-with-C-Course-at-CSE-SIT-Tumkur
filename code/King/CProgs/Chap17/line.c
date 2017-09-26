/* line.c
 *
 * Solution to Programming Project 4 (Chapter 17)
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
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
  char *word;
  struct node *next;
};

struct node *line = NULL, *tail = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  struct node *p;

  while (line != NULL) {
    p = line;
    line = line->next;
    free(p->word);
    free(p);
  }
  tail = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  if (line == NULL)
    line = tail = malloc(sizeof(struct node));
  else {
    tail->next = malloc(sizeof(struct node));
    tail = tail->next;
    line_len++;
  }
  if (tail == NULL) {
    printf("Error: malloc failed in add_word\n");
    exit(EXIT_FAILURE);
  }
  tail->word = malloc(strlen(word) + 1);
  if (tail->word == NULL) {
    printf("Error: malloc failed in add_word\n");
    exit(EXIT_FAILURE);
  }
  strcpy(tail->word, word);
  tail->next = NULL;
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, j;
  struct node *p;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (p = line; p != NULL; p = p->next) {
    printf("%s", p->word);
    if (num_words > 1) {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line(void)
{
  struct node *p;

  if (line_len == 0)
    return;
  for (p = line; p != NULL; p = p->next) {
    if (p != line)
      putchar(' ');
    printf("%s", p->word);
  }
  putchar('\n');
}
