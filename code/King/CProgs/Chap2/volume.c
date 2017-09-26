/* volume.c
 *
 * Solution to Programming Project 2 (Chapter 2)
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

  radius = 10.0f;
  volume = (4.0f / 3.0f) * PI * radius * radius * radius;

  printf("Volume (cubic meters): %.1f\n", volume);

  /*
   * Note: If (4/3) is used in the volume expression, its value
   * is one and the volume is incorrectly computed as 3141.6.
   */

  return 0;
}
