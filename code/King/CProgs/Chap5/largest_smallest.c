/* largest_smallest.c
 *
 * Solution to Programming Project 7 (Chapter 5)
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
  int n1, n2, n3, n4,
      larger12, smaller12,   /* larger and smaller of n1 and n2 */
      larger34, smaller34,   /* larger and smaller of n3 and n4 */
      largest, smallest;     /* largest and smallest overall */

  printf("Enter four integers: ");
  scanf("%d%d%d%d", &n1, &n2, &n3, &n4);

  if (n1 > n2) {
    larger12 = n1;
    smaller12 = n2;
  } else {
    larger12 = n2;
    smaller12 = n1;
  }

  if (n3 > n4) {
    larger34 = n3;
    smaller34 = n4;
  } else {
    larger34 = n4;
    smaller34 = n3;
  }

  if (larger12 > larger34)
    largest = larger12;
  else
    largest = larger34;

  if (smaller12 < smaller34)
    smallest = smaller12;
  else
    smallest = smaller34;

  printf("Largest: %d\n", largest);
  printf("Smallest: %d\n", smallest);

  return 0;
}
