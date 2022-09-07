#include <stdio.h>

int main() {
    int x[3];
    int *p;

    for(p = x; p < x+3; p++) scanf("%d", p);

    if(*(x+0) < *(x+1))
    {
        if(*(x+1) < *(x+2)) p = x+1;
        else if(*(x+2)<*(x+0)) p = x;
        else p = x+2;
    }
    else 
    {
        if(*(x+0) < *(x+2)) p = x;
        else if(*(x+2) < *(x+1)) p = x+1;
        else p = x+2;
    }

    printf("%d\n", *p);
    return 0;
}