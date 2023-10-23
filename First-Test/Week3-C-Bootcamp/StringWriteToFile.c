#include <stdio.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int num_lines;
    float total = 0;
    char word[1000];


    printf("How many strings do you want to type?: \n");
    scanf("%d",&num_lines);
    
    printf("Type %d words: ", num_lines);
    
    for (int i = 0; i < num_lines; i++)
    {
        
        scanf("%s", word);
        fprintf(file, "%s\n", word);

    }

    fclose(file);
    return 0;
}