#include <stdio.h>

int countString(char* word){

    int count;
    for (count = 0; count < sizeof(word); count ++){

    }
    


    return count;
}

int main(){

    int result;
    char string[100];

    printf("Enter a string:\n");
    scanf("%s",string);
    result = countString(string);
    printf("%d\n",result);

    return 0;


}