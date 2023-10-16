#include <stdio.h>

int main(){

    int mysterynumber;

    while (mysterynumber != -1){
        printf("Enter a number:\n");
        scanf("%d",&mysterynumber);
        if (mysterynumber == -1){
            printf("Process Terminated\n");
        }
        else if (mysterynumber >= 0 && mysterynumber <= 100){
            printf("%d is in the range 0 to 100\n", mysterynumber);
        }
        else  
        {
            printf("%d is not in the range 0 to 100\n", mysterynumber);
        }
    }
    return 0;




}