/* flights.c
 *
 * Solution to Programming Project 5 (Chapter 16)
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

#define HOURS_PER_HALF_DAY 12
#define MINUTES_PER_HOUR 60
#define MINUTES_PER_HALF_DAY (HOURS_PER_HALF_DAY * MINUTES_PER_HOUR)

#define SIZE ((int) (sizeof(flights) / sizeof(flights[0])))

struct flight {
  int departure, arrival;
};

void put_time(int time);

int main(void)
{
  struct flight flights[] = {
    {480, 616}, {583,  712}, { 679,  811}, { 767,  900},
    {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}
  };
  int hours, minutes, time, closest;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);
  time = hours * MINUTES_PER_HOUR + minutes;

  if (time <= flights[0].departure)
    closest = 0;
  else if (time > flights[SIZE-1].departure)
    closest = SIZE - 1;
  else {
    closest = 0;
    while (time > flights[closest+1].departure)
      closest++;
    if (flights[closest+1].departure - time <
        time - flights[closest].departure)
      closest++;
  }

  printf("Closest departure time is ");
  put_time(flights[closest].departure);
  printf(", arriving at ");
  put_time(flights[closest].arrival);
  printf("\n");

  return 0;
}

/***********************************************************
 * put_time: Writes a time given in minutes past midnight. *
 ***********************************************************/
void put_time(int time)
{
  int hour = time / MINUTES_PER_HOUR;

  if (hour == 0)
    hour = HOURS_PER_HALF_DAY;
  else if (hour > HOURS_PER_HALF_DAY)
    hour -= HOURS_PER_HALF_DAY;

  printf("%d:%.2d ", hour, time % MINUTES_PER_HOUR);
  if (time < MINUTES_PER_HALF_DAY)
    printf("a.m.");
  else
    printf("p.m.");
}
