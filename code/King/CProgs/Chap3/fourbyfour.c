/* fourbyfour.c
 *
 * Solution to Programming Project 5 (Chapter 3)
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
  int num01, num02, num03, num04, num05, num06, num07, num08,
      num09, num10, num11, num12, num13, num14, num15, num16;
  int row1, row2, row3, row4;   /* row sums */
  int col1, col2, col3, col4;   /* column sums */
  int diag1, diag2;             /* diagonal sums */

  printf("Enter the numbers from 1 to 16 in any order: ");
  scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
        &num01, &num02, &num03, &num04, &num05, &num06, &num07, &num08,
        &num09, &num10, &num11, &num12, &num13, &num14, &num15, &num16);

  row1 = num01 + num02 + num03 + num04;
  row2 = num05 + num06 + num07 + num08;
  row3 = num09 + num10 + num11 + num12;
  row4 = num13 + num14 + num15 + num16;

  col1 = num01 + num05 + num09 + num13;
  col2 = num02 + num06 + num10 + num14;
  col3 = num03 + num07 + num11 + num15;
  col4 = num04 + num08 + num12 + num16;

  diag1 = num01 + num06 + num11 + num16;
  diag2 = num04 + num07 + num10 + num13;

  printf("\n");   /* blank line */
  printf("%2d %2d %2d %2d\n", num01, num02, num03, num04);
  printf("%2d %2d %2d %2d\n", num05, num06, num07, num08);
  printf("%2d %2d %2d %2d\n", num09, num10, num11, num12);
  printf("%2d %2d %2d %2d\n", num13, num14, num15, num16);
  printf("\n");
  printf("Row sums: %d %d %d %d\n", row1, row2, row3, row4);
  printf("Column sums: %d %d %d %d\n", col1, col2, col3, col4);
  printf("Diagonal sums: %d %d\n", diag1, diag2);

  return 0;
}
