/* remind_c.c
 *
 * Solution to Programming Project 2(c) (Chapter 13)
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
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */
#define DATE_LEN 5      /* length of date string */

int read_line(char str[], int n);

int main(void)
{
  char reminders[MAX_REMIND][DATE_LEN+MSG_LEN+1];
  char date_str[DATE_LEN+1], msg_str[MSG_LEN+1];
  int month, day, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter date (mm/dd) and reminder: ");
    scanf("%d", &month);
    if (month == 0)
      break;
    scanf("/%d", &day);
    sprintf(date_str, "%2d/%02d", month, day);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(date_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], date_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\n Date Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf("%s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
