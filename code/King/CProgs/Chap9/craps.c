/* craps.c
 *
 * Solution to Programming Project 8 (Chapter 9)
 *
 * From C PROGRAMMING: A MODERN APPROACH (Second Edition)
 *
 * Copyright (c) 2008 W. W. Norton & Company
 * All rights reserved.
 *
 * This program may be freely distributed for class use,
 * provided that this copyright notice is retained.
 */

#include <ctype.h>
#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
  int wins = 0, losses = 0;
  char again;

  srand((unsigned) time(NULL));

  do {
    if (play_game()) {
      printf("You win!\n\n");
      wins++;
    } else {
      printf("You lose!\n\n");
      losses++;
    }

    printf("Play again? ");
    scanf(" %c", &again);

    printf("\n");   /* blank line */
  } while (tolower(again) == 'y');

  printf("Wins: %d  Losses: %d\n", wins, losses);

  return 0;
}

int roll_dice(void)
{
  return (rand() % 6 + 1) + (rand() % 6 + 1);
}

bool play_game(void)
{
  int roll, point;

  roll = roll_dice();
  printf("You rolled: %d\n", roll);

  switch (roll) {
    case 7: case 11:
      return true;
    case 2: case 3: case 12:
      return false;
  }

  point = roll;
  printf("Your point is %d\n", point);

  for (;;) {
    roll = roll_dice();
    printf("You rolled: %d\n", roll);

    if (roll == point)
      return true;
    else if (roll == 7)
      return false;
  }
}
