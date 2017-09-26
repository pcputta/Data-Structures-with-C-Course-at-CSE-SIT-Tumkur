/* volume2.c
 *
 * Solution to Programming Project 3 (Chapter 2)
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

#define PI 3.14159f

int main(void)
{
  float volume, radius;

  printf("Enter radius of sphere: ");
  scanf("%f", &radius);

  volume = (4.0f / 3.0f) * PI * radius * radius * radius;

  printf("Volume (cubic meters): %.1f\n", volume);

  return 0;
}
