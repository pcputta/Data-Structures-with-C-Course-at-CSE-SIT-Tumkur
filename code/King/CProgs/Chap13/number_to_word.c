/* number_to_word.c
 *
 * Solution to Programming Project 7 (Chapter 13)
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

int main(void)
{
  int n;
  char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                   "sixteen", "seventeen", "eighteen", "nineteen"},
       *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty",
                  "seventy", "eighty", "ninety"},
       *ones[] = {"one", "two", "three", "four", "five",
                  "six", "seven", "eight", "nine"};

  printf("Enter a two-digit number: ");
  scanf("%d", &n);

  printf("You entered the number ");
  if (n < 20)
    printf("%s", teens[n - 10]);
  else
    printf("%s-%s", tens[(n / 10) - 2], ones[(n % 10) - 1]);
  printf(".\n");

  return 0;
}
