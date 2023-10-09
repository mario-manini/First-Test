#include <stdio.h>
#include <limits.h>

int main(){
    printf("%d\n",__INT_MAX__);
    printf("%f\n",__FLT_MAX__);
    printf("%f\n",__DBL_MAX__);
    printf("%d\n",__WCHAR_MAX__);
    return 0;
}

