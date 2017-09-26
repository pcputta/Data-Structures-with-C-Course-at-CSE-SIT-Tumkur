#include <stdio.h>
#include <stdlib.h>


typedef struct{
	unsigned int first_visit:1;
	unsigned int come_again:1;
	unsigned int rating:4;
	unsigned int days_a_week:3;	
}survey_t;

int main()
{
	survey_t mallsurvey;
	int response;

	printf("\nSurvey Form\n");

	printf("\nIs this your first visit? enter 0 or 1: ");
//	scanf("%d",&mallsurvey.first_visit);		//error
	scanf("%d",&response);
	mallsurvey.first_visit = response;
	printf("\nWill you come again? enter 0 or 1: ");
	scanf("%d",&response);
	mallsurvey.come_again = response;
	printf("\nEnter your service rating (1-10) : ");
	scanf("%d",&response);
	mallsurvey.rating = response;
	printf("\nHow many days a week would you visit if you could? : ");
	scanf("%d",&response);
	mallsurvey.days_a_week = response;

	printf("\nThanks for your response\n");

	printf("\nMemory allocated to survey_t type is %ld bytes\n",sizeof(survey_t));
	return 0;

}
