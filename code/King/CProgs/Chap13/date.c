/* date.c
 *
 * Solution to Programming Project 18 (Chapter 13)
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
  int month, day, year;
  char *months[] = {"January", "February", "March", "April", "May",
                    "June", "July", "August", "September", "October",
                    "November", "December"};

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("You entered the date %s %d, %d\n", months[month-1], day, year);

  return 0;
}
