/* broker.c
 *
 * Solution to Programming Project 3 (Chapter 5)
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
  int shares;
  float price, value, commission, rival_commission;

  printf("Enter number of shares: ");
  scanf("%d", &shares);
  printf("Enter price per share: ");
  scanf("%f", &price);

  value = shares * price;

  if (value < 2500.00f)
    commission = 30.00f + .017f * value;
  else if (value < 6250.00f)
    commission = 56.00f + .0066f * value;
  else if (value < 20000.00f)
    commission = 76.00f + .0034f * value;
  else if (value < 50000.00f)
    commission = 100.00f + .0022f * value;
  else if (value < 500000.00f)
    commission = 155.00f + .0011f * value;
  else
    commission = 255.00f + .0009f * value;

  if (commission < 39.00f)
    commission = 39.00f;

  rival_commission = 33.00f + (shares < 2000 ? .03f : .02f) * shares;

  printf("\n");   /* blank line */
  printf("Broker's commission: $%.2f\n", commission);
  printf("Rival broker's commission: $%.2f\n", rival_commission);

  return 0;
}
