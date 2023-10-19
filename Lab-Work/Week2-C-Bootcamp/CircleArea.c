#include <stdio.h>

int CircleArea (float radius){

    float area;
    area = radius * radius * 3.1412;
    return area;
}



int main (){

    float rad;
    float result;
    printf("Enter a radius for the circle:\n");
    scanf("%f",&rad);
    result = CircleArea (rad);
    printf("The area of the circle is %.3f\n",result);

}