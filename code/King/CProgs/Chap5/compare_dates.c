/* compare_dates.c
 *
 * Solution to Programming Project 9 (Chapter 5)
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

/* Note: Program assumes years are in the same century. */

int main(void)
{
  int month1, day1, year1, month2, day2, year2;
  bool first_earlier;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month1, &day1, &year1);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month2, &day2, &year2);

  if (year1 != year2)
    first_earlier = (year1 < year2);
  else if (month1 != month2)
    first_earlier = (month1 < month2);
  else
    first_earlier = (day1 < day2);

  if (first_earlier)
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
           month1, day1, year1, month2, day2, year2);
  else
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
           month2, day2, year2, month1, day1, year1);

  return 0;
}
