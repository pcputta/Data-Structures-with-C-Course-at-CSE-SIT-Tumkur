/* flights.c
 *
 * Solution to Programming Project 10 (Chapter 8)
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

#define SIZE ((int) (sizeof(departures) / sizeof(departures[0])))

int main(void)
{
  int departures[] = {480, 583, 679, 767, 840,  945, 1140, 1305},
      arrivals[]   = {616, 712, 811, 900, 968, 1075, 1280, 1438};

  int hours, minutes, time, closest, arrival_hour, departure_hour;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);
  time = hours * MINUTES_PER_HOUR + minutes;

  if (time <= departures[0])
    closest = 0;
  else if (time > departures[SIZE-1])
    closest = SIZE - 1;
  else {
    closest = 0;
    while (time > departures[closest+1])
      closest++;
    if ((departures[closest+1] - time) < (time - departures[closest]))
      closest++;
  }

  printf("Closest departure time is ");

  departure_hour = departures[closest] / MINUTES_PER_HOUR;
  if (departure_hour == 0)
    departure_hour = HOURS_PER_HALF_DAY;
  else if (departure_hour > HOURS_PER_HALF_DAY)
    departure_hour -= HOURS_PER_HALF_DAY;
  printf("%d:%.2d ", departure_hour, departures[closest] % MINUTES_PER_HOUR);
  if (departures[closest] < MINUTES_PER_HALF_DAY)
    printf("a.m.");
  else
    printf("p.m.");

  printf(", arriving at ");

  arrival_hour = arrivals[closest] / MINUTES_PER_HOUR;
  if (arrival_hour == 0)
    arrival_hour = HOURS_PER_HALF_DAY;
  else if (arrival_hour > HOURS_PER_HALF_DAY)
    arrival_hour -= HOURS_PER_HALF_DAY;
  printf("%d:%.2d ", arrival_hour, arrivals[closest] % MINUTES_PER_HOUR);
  if (arrivals[closest] < MINUTES_PER_HALF_DAY)
    printf("a.m.");
  else
    printf("p.m.");
  printf("\n");

  return 0;
}
