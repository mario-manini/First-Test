#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age: ");
    // need and sign because computer doesn't know memory address
    scanf("%d", &age);
    printf("Your age is %d\n", age);
    return 0;
}
