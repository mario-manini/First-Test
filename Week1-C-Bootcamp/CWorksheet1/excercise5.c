#include <stdio.h>

int main(){

    float a;
    float b;

    a = 3.15;
    b = 10.2;

    float c;

    c = a;
    a = b;
    b = c;

    printf("a is now %.3f and b is now %.3f\n",a,b);

    return 0;
}