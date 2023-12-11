#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data

typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Function to tokenize a record
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

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


    free(inputCopy);

}


int main()
{
    char filename[1000];
    int MAXCHAR = 1000;
    char row[MAXCHAR];
    int count = 0;
    char date[100];
    char time[100];
    char steps[100];
    FITNESS_DATA data[1000];

    printf("Input Filename: \n");
    scanf("%s", filename);
    FILE *FitnessData;
    FitnessData = fopen(filename, "r");
    if (FitnessData == NULL)
    {
        printf("Error: could not open file\n");
        return 1;
    }

    while (fgets(row, MAXCHAR, FitnessData))
    {
        tokeniseRecord(row, ",", date, time, steps);
        strcpy(data[count].date, date);
        strcpy(data[count].time, time);
        data[count].steps = atoi(steps);
        int timelength = strlen(time);
        const char *lasttimechar = &time[timelength-1];
        int datelength = strlen(date);
        const char *lastdatechar = &date[datelength-1];

        if ((strcmp(steps,"\n") == 0) || (strcmp(lasttimechar,"\n") == 0) || (strcmp(lastdatechar,"\n") == 0)){
            printf("Error: invald file");
            break;
        }
        count += 1;
    }
    int totalRecords = count;
    int i;
    int b;

    for (b=0;b< totalRecords;b++){

        for (i =0; i < totalRecords-1;i++){
            if (data[i].steps < data[i+1].steps){
                int tempsteps;
                tempsteps = data[i].steps;
                data[i].steps = data[i+1].steps;
                data[i+1].steps = tempsteps;

                char tempdate[10000];
                strcpy(tempdate,data[i].date);
                strcpy(data[i].date,data[i+1].date);
                strcpy(data[i+1].date,tempdate);

                char temptime[10000];
                strcpy(temptime,data[i].time);
                strcpy(data[i].time,data[i+1].time);
                strcpy(data[i+1].time,temptime);
            }
        }
    }

    //sort data in array according to steps


    char* sortedfilename = strcat(filename,".tsv");

    FILE *file = fopen (sortedfilename, "w"); 
    int a = 0;

    for (a =0; a < totalRecords;a++){
        fprintf(file, "%s\t%s\t%d\n",data[a].date,data[a].time,data[a].steps);
    }


    fclose(file);
    return 0;

}

