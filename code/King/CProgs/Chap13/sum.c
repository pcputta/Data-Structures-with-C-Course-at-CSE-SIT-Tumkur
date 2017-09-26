/* sum.c
 *
 * Solution to Programming Project 5 (Chapter 13)
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
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i, sum = 0;

  for (i = 1; i < argc; i++)
    sum += atoi(argv[i]);

  printf("Total: %d\n", sum);

  return 0;
}
