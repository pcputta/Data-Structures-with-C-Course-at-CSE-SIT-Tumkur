/* balance.c
 *
 * Solution to Programming Project 9 (Chapter 6)
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

#define MONTHS_PER_YEAR 12
#define PERCENT 100.0f

int main(void)
{
  float loan_amount, interest_rate, monthly_payment, monthly_interest_rate, balance;
  int num_payments, i;

  printf("Enter amount of loan: ");
  scanf("%f", &loan_amount);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);
  printf("Enter number of payments: ");
  scanf("%d", &num_payments);

  monthly_interest_rate = (interest_rate / PERCENT) / MONTHS_PER_YEAR;
  balance = loan_amount;

  printf("\n");   /* blank line */

  for (i = 1; i <= num_payments; i++) {
    balance += -monthly_payment + (balance * monthly_interest_rate);
    printf("Balance remaining after payment #%d: $%.2f\n", i, balance);
  }

  return 0;
}
