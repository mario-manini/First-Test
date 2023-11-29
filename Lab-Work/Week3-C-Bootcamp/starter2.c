#include <stdio.h>
#include <stdlib.h>

int main(){

    char* filename = "input.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int num;
    int nums[200] = {};
    int count = 0;
    
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        num = atoi(line_buffer);
        nums[count] = num;
        count += 1;
    }

    int count1;

    for (count1 = 0; count1 < 200; count1 ++){

        printf("%d\n",nums[count1]);

    }
    
    fclose(file);
    return 0;
}   