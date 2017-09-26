/* time.c
 *
 * Solution to Programming Project 9 (Chapter 7)
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

int main(void)
{
  int hours12, hours24, minutes;
  char am_pm;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &hours12, &minutes, &am_pm);

  /* Note: scanf potentially leaves an 'm' in the keyboard buffer. If the
   * program had included additional input, the rest of the input line would
   * need to be skipped before continuing (e.g., using the idiom on p. 141).
   */

  hours24 = hours12 % 12;
  if (toupper(am_pm) == 'P')
    hours24 += 12;

  printf("Equivalent 24-hour time: %.2d:%.2d\n", hours24, minutes);

  return 0;
}
