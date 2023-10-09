#include <stdio.h>

int main()
{
    float a;
    float b;
    printf("Enter the length of the rectangle: ");
    scanf("%f", &a);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &b);
    float c;
    c = a * b;
    printf("The area of the rectangle is %.3f\n", c);
    return 0;
}