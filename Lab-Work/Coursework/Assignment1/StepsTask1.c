#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Define any additional variables here
// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}





int main()
{

    FITNESS_DATA data[1000];
    int MAXCHAR = 1000;
    FILE *FitnessData;
    char row[MAXCHAR];
    int count = 0;
    char date[100];
    char time[100];
    char steps[100];
    FitnessData = fopen("FitnessData_2023.csv", "r");

    while (fgets(row, MAXCHAR, FitnessData))
    {

        tokeniseRecord(row,",",date,time,steps);
        strcpy(data[count].date, date);
        strcpy(data[count].time, time);
        data[count].steps = atoi(steps);

        count += 1;
    }

    printf("Number of records in file: %d\n", count);

    int i;
    for (i = 0; i < 3; i++)
    {
        if (i < count){
            printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
        }

    }

    return 0;

    // assign each line to struct
}