/* quicksort.h
 *
 * Solution to Programming Project 3 (Chapter 15)
 *
 * From C PROGRAMMING: A MODERN APPROACH (Second Edition)
 *
 * Copyright (c) 2008 W. W. Norton & Company
 * All rights reserved.
 *
 * This program may be freely distributed for class use,
 * provided that this copyright notice is retained.
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

#endif
