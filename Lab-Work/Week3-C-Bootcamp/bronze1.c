#include "utils.h"

int main(){

    int n;
    int count;
    printf("Enter a number for n:\n");
    scanf("%d",&n);

    char *filename = "squares.dat";
    FILE *file = fopen(filename, "w");

    for (count = 0;count < n; count ++){

        fprintf(file,"%d\n",n*n);

    }

    fclose(file);

    return 0;

}