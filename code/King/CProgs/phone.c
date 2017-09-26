/* phone.c
 *
 * Solution to Programming Project 4 (Chapter 3)
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
  int area_code, prefix, number;

  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%d)%d-%d", &area_code, &prefix, &number);

  printf("You entered %d.%d.%d\n", area_code, prefix, number);

  return 0;
}
