#include <stdio.h>

int main(){
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f",&radius);
    float area;
    area = 3.14153 * radius * radius;
    printf("The area of the circle is %.3f\n", area);
    return 0;
}