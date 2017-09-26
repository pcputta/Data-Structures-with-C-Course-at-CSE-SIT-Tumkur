/* print_float.c
 *
 * Solution to Programming Project 1 (Chapter 20)
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

struct IEEE_float {
  unsigned int fraction: 23;   /* members may need to be reversed */
  unsigned int exponent: 8;
  unsigned int sign: 1;
};

union dual_float {
  float f;
  struct IEEE_float IEEE;
};

int main(void)
{
  union dual_float dual;

  dual.IEEE.sign = 1;
  dual.IEEE.exponent = 128;
  dual.IEEE.fraction = 0;

  printf("Value: %g\n", dual.f);

  return 0;
}
