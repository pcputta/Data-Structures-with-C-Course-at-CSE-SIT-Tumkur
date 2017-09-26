/* compare_dates.c
 *
 * Solution to Programming Project 10 (Chapter 6)
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
  int month, day, year, earliest_month, earliest_day, earliest_year;
  bool earlier_date;

  printf("Enter a date (mm/dd/yy): ");
  scanf("%d/%d/%d", &earliest_month, &earliest_day, &earliest_year);

  for (;;) {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    if (month == 0 && day == 0 && year == 0)
      break;

    if (year != earliest_year)
      earlier_date = (year < earliest_year);
    else if (month != earliest_month)
      earlier_date = (month < earliest_month);
    else
      earlier_date = (day < earliest_day);

    if (earlier_date) {
      earliest_month = month;
      earliest_day = day;
      earliest_year = year;
    }
  }

  printf("%d/%d/%.2d is the earliest date\n",
         earliest_month, earliest_day, earliest_year);

  return 0;
}
