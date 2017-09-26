/* repdigit.c
 *
 * Solution to Programming Project 1 (Chapter 8)
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
  int digit_count[10] = {0};
  bool repeated_digits = false;
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    if (digit_count[digit] > 0)
      repeated_digits = true;
    digit_count[digit]++;
    n /= 10;
  }

  if (repeated_digits) {
    printf("Repeated digit(s):");
    for (digit = 0; digit < 10; digit++)
      if (digit_count[digit] > 1)
        printf(" %d", digit);
    printf("\n");
  } else
    printf("No repeated digit\n");

  return 0;
}
