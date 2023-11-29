#include <stdio.h>

int main(){

    int i;
    const int SIZE = 5;
    int nums[SIZE] = {1,2,3,4,5};
    int count = 0;

    for (i = 0; i <= SIZE; i++){
        count += nums[i];
    }

    printf("The sum of the array is %d\n", count);

    return 0;


