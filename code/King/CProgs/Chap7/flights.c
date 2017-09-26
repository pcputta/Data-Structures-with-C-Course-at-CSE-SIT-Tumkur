/* flights.c
 *
 * Solution to Programming Project 8 (Chapter 7)
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
#include <stdio.h>

int main(void)
{
  int hours, minutes, time, closest;
  char am_pm;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &hours, &minutes, &am_pm);

  /* Note: scanf potentially leaves an 'm' in the keyboard buffer. If the
   * program had included additional input, the rest of the input line would
   * need to be skipped before continuing (e.g., using the idiom on p. 141).
   */

  time = (hours % 12) * 60 + minutes;
  if (toupper(am_pm) == 'P')
    time += 12 * 60;   /* advance time by twelve hours */

  /* Bound the time entered by the user between two successive departures,
   * then determine which one is closer.
   */
  if (time <= 480) /* 8:00 a.m. */
    closest = 480;
  else if (time <= 583) /* 9:43 a.m. */
    closest = (time - 480) <= (583 - time) ? 480 : 583;
  else if (time <= 679) /* 11:19 a.m. */
    closest = (time - 583) <= (679 - time) ? 583 : 679;
  else if (time <= 767) /* 12:47 p.m. */
    closest = (time - 679) <= (767 - time) ? 679 : 767;
  else if (time <= 840) /* 2:00 p.m. */
    closest = (time - 767) <= (840 - time) ? 767 : 840;
  else if (time <= 945) /* 3:45 p.m. */
    closest = (time - 840) <= (945 - time) ? 840 : 945;
  else if (time <= 1140) /* 7:00 p.m. */
    closest = (time - 945) <= (1140 - time) ? 945 : 1140;
  else /* 9:45 p.m. */
    closest = (time - 1140) <= (1305 - time) ? 1140 : 1305;

  /* Display departure and arrival times. Code from Programming Project 2 in Chapter
   * 5 could be used here, but arrival time would need to be stored in a variable.
   */
  switch (closest) {
    case 480:
      printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
      break;
    case 583:
      printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
      break;
    case 679:
      printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
      break;
    case 767:
      printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
      break;
    case 840:
      printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
      break;
    case 945:
      printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
      break;
    case 1140:
      printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
      break;
    case 1305:
      printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
      break;
  }

  return 0;
}
