#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char acName[30];
    char acNationality[30];
    int iMatches, iWickets, iOvers, iRuns;
}BOWLER;

int main(void)
{
    BOWLER bowlers[5];
    int i, iPosEconomy=0, iPosStrRate=0;
    float fEconomy[5], fStrRate[5], fBestEconomy,fBestStrRate;
    printf("\nEnter details\n");

    for(i=0;i<5;i++)
    {
        printf("Name : ");
        scanf("%s", bowlers[i].acName);
        printf("Nationality : ");
        scanf("%s",bowlers[i].acNationality);
        printf("Matches Played : ");
        scanf("%d", &bowlers[i].iMatches);
        printf("Wickets taken : ");
        scanf("%d", &bowlers[i].iWickets);
        printf("Overs Bowled : ");
        scanf("%d", &bowlers[i].iOvers);
        printf("Runs Conceded : ");
        scanf("%d", &bowlers[i].iRuns);
    }

    fBestEconomy = fEconomy[0] = (float)bowlers[0].iRuns/bowlers[0].iOvers;
    fBestStrRate = fStrRate[0] = (float)bowlers[0].iOvers/bowlers[0].iWickets;
    printf("\n\nName\t\tNation\t\tMatches  Wickets   Overs  Runs  Economy   SR\n");

    for(i=0;i<5;i++)
    {
        fEconomy[i] = (float)bowlers[i].iRuns/bowlers[i].iOvers;
        fStrRate[i] = (float)bowlers[i].iOvers/bowlers[i].iWickets;
        printf("%-16s", bowlers[i].acName);
        printf("%-10s\t",bowlers[i].acNationality);
        printf("%3d", bowlers[i].iMatches);
        printf("%9d", bowlers[i].iWickets);
        printf("%12d", bowlers[i].iOvers);
        printf("%6d", bowlers[i].iRuns);
        printf("%8.2f",fEconomy[i]);
        printf("%8.2f",fStrRate[i]);
        printf("\n");

        if(fBestEconomy > fEconomy[i])
            iPosEconomy = i;
        if(fBestStrRate > fStrRate[i])
            iPosStrRate = i;
    }
    printf("\nThe Bowler with the best economy is : %s\n", bowlers[iPosEconomy].acName);
    printf("\nThe Bowler with the best Strike rate is : %s\n", bowlers[iPosStrRate].acName);
    return 0;
}

