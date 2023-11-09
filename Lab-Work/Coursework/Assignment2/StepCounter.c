#include <stdio.h>
#include "FitnessDataStruct.h"



int main()
{

    char choice;
    char a[] = 'A';
    char choice;

    while (!(strcmp(choice,a) == 0))
    {
        printf("Enter a Letter: \n");
        scanf("%c", choice);
    }

    switch (choice)
    {
    case 'A':
        printf("Option 0 has been selected\n");
        break;


    default:
        printf("A different option has been selected\n");
    }


    //A
    char filename[1000];
    printf("Input Filename: \n");
    scanf("%s",filename);
    printf("%s\n",filename);






















    FITNESS_DATA data[1000];
    int MAXCHAR = 1000;
    FILE *FitnessData;
    char row[MAXCHAR];
    int count = 0;
    char date[100];
    char time[100];
    char steps[100];
    FitnessData = fopen("FitnessData.csv", "r");
    while (fgets(row, MAXCHAR, FitnessData))
    {
        tokeniseRecord(row, ",", date, time, steps);
        strcpy(data[count].date, date);
        strcpy(data[count].time, time);
        data[count].steps = atoi(steps);
        count += 1;
    }

    printf("Number of records in file: %d\n", count);
    int i;
    for (i = 0; i < 3; i++)
    {
        if (i < count)
        {
            printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
        }
    }
    return 0;
}
