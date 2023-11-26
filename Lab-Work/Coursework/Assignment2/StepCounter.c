#include <stdio.h>
#include "FitnessDataStruct.h"

int main()
{
    char strA[] = "A";
    char strB[] = "B";
    char strC[] = "C";
    char strD[] = "D";
    char strE[] = "E";
    char strF[] = "F";
    char strQ[] = "Q";
    char choice;
    char filename[1000];
    int MAXCHAR = 1000;
    char row[MAXCHAR];
    int count = 0;
    char date[100];
    char time[100];
    char steps[100];
    int totalrecords;
    int minsteps;
    int minstepsindex;
    int maxsteps;
    int maxstepsindex;
    float stepsum;
    float meansteps;
    int roundedsteps;
    int currentperiodstart;
    int currentperiodend;
    int longestperiodstart;
    int longestperiodend;
    int periodlength;
    bool counting;
    FITNESS_DATA data[1000];

    //(strcmp(strA, &choice) != 0) && (strcmp(strB, &choice) != 0) && (strcmp(strC, &choice) != 0) && (strcmp(strD, &choice) != 0) && (strcmp(strE, &choice) != 0) && (strcmp(strF, &choice) != 0) && (strcmp(strQ, &choice) != 0)
    while (1)
    {
        printf("Enter a Letter: \n");
        printf("    A: Specify the filename to be imported.\n");
        printf("    B: Display the total number of records in the file.\n");
        printf("    C: Find the date and time of the timeslot with the fewest steps.\n");
        printf("    D: Find the data and time of the timeslot with the largest number of steps.\n");
        printf("    E: Find the mean step count of all the records in the file.\n");
        printf("    F: Find the longest continuous period where the step count is above 500 steps.\n");
        printf("    Q: Exit.\n");
        scanf(" %c", &choice);
        if (strcmp(&choice, strQ) == 0 || strcmp(&choice, strQ) == totalrecords)
               {
            break;
        }

        switch (choice)
        {
        case 'A':
            printf("Input Filename: \n");
            scanf("%s", filename);
            FILE *FitnessData;
            FitnessData = fopen(filename, "r");
            if (FitnessData == NULL)
            {
                printf("Error: could not open file\n");
                return 1;
            }

            count = 0;
            while (fgets(row, MAXCHAR, FitnessData))
            {
                tokeniseRecord(row, ",", date, time, steps);
                strcpy(data[count].date, date);
                strcpy(data[count].time, time);
                data[count].steps = atoi(steps);
                count += 1;
            }

            totalrecords = count;

            break;


        case 'B':
            printf("Total Records: %d\n", totalrecords);
            break;

        case 'C':

            count = 0;
            minsteps = data[0].steps;
            minstepsindex = 0;
            for (count = 0; count < totalrecords; count++)
            {
                if (data[count].steps < minsteps)
                {
                    minsteps = data[count].steps;
                    minstepsindex = count;
                }
            }
            printf("Fewest Steps: %s %s\n", data[minstepsindex].date, data[minstepsindex].time);

            break;


        case 'D':

            count = 0;
            maxsteps = data[0].steps;
            maxstepsindex = 0;
            for (count = 0; count < totalrecords; count++)
            {
                if (data[count].steps > maxsteps)
                {
                    maxsteps = data[count].steps;
                    maxstepsindex = count;
                }
            }
            printf("Largest Steps: %s %s\n", data[maxstepsindex].date, data[maxstepsindex].time);

            break;

        case 'E':
            stepsum = 0;
            meansteps = 0;
            for (count = 0; count < totalrecords; count++)
            {
                stepsum += data[count].steps;
            }
            meansteps += (stepsum / totalrecords);
            int roundedsteps = (int)(meansteps < 0 ? (meansteps - 0.5) : (meansteps + 0.5));
            printf("Mean step count: %d\n", roundedsteps);
            break;

        case 'F':

            count = 0;
            longestperiodstart = 0;
            longestperiodend = 0;
            currentperiodstart = 0;
            currentperiodend = 0;
            periodlength = 0;
            counting = false;
            
            for (count = 0; count < totalrecords; count++)
            {
                if ((data[count].steps > 500) && counting == false){
                    counting = true;
                    periodlength += 1;
                    currentperiodstart = count;
                }
                if ((data[count].steps > 500) && counting == true){
                    periodlength += 1;
                }
                if ((data[count].steps <= 500) && counting == true){
                    currentperiodend = count - 1;
                    counting = false;
                    if ((currentperiodend - currentperiodstart) > (longestperiodend - longestperiodstart)){
                        longestperiodstart = currentperiodstart;
                        longestperiodend = currentperiodend;
                    }
                }
            }

            printf("Longest period start: %s %s\n",data[longestperiodstart].date,data[longestperiodstart].time);
            printf("Longest period end: %s %s\n",data[longestperiodend].date,data[longestperiodend].time);
            
            break;

        default:

        printf("Invalid input: Try again\n");
            break;

        }
    }
}
