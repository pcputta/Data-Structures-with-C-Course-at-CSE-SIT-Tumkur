/* repdigit2.c
 *
 * Solution to Programming Project 3 (Chapter 8)
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
  bool digit_seen[10];
  int digit;
  long n;

  for (;;) {
    printf("Enter a number: ");
    scanf("%ld", &n);
    if (n <= 0)
      break;

    for (digit = 0; digit < 10; digit++)
      digit_seen[digit] = false;

    while (n > 0) {
      digit = n % 10;
      if (digit_seen[digit])
        break;
      digit_seen[digit] = true;
      n /= 10;
    }

    if (n > 0)
      printf("Repeated digit\n");
    else
      printf("No repeated digit\n");
  }

  return 0;
}
