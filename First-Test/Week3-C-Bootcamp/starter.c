#include <stdio.h>

int main()
{

    int count;
    int nums[10] = {};
    int total;
    float mean;

    for (count = 0; count < 10; count++)
    {
        printf("Enter a number: \n");
        scanf("%d", nums[count]);
        total += nums[count];
    }

    mean = total / 10;

    for (count = 0; count < 10; count ++){
        printf("%d\n",nums[count]);



    }
    printf("%f\n",mean);
}