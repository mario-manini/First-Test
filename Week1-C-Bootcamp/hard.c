#include <stdio.h>
#include <math.h>

// 6 * (1 + 1/4 + 1/9 + 1/16)
int main(){

    int i;
    float count;
    count = 1;

    for (i = 2; i < 60000; i++){
        count += 1/(i*i);
    }
    
    float new;
    new = count * 6;
    printf("%f\n",pow(new,0.5));



    return 0;
}