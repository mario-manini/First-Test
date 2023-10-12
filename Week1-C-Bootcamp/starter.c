#include <stdio.h>

int main(){

    float a;
    float b;
    printf("Enter number 1: ");
    scanf("%f",&a);
    printf("Enter number 2: ");
    scanf("%f",&b);
    float c;
    c = a + b;
    printf("The sum of these numbers is %.3f\n",c);
    return 0;
}