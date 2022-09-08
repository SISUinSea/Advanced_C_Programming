#include <stdio.h>
int* mid(int *array);
int main() {
    int x[3];
    int *px;

    for(px = x; px < x + 3; px++)
    {
        scanf("%d", px);
    }

    printf("%d\n", *mid(x));

    return 0;
}

int* mid(int *x){
    int *medianIndex;
    if(*(x+0) < *(x+1))
    {
        if(*(x+2) < *(x+0))
        {
            medianIndex = x;
        }
        else
        {
            if(*(x+1) < *(x+2))
            {
                medianIndex = x+1;
            }
            else 
            {
                medianIndex = x+2;
            }
        }
    }
    else
    {
        if(*(x+2) < *(x+1))
        {
            medianIndex = x+1;
        }
        else 
        {
            if(*(x+0) < *(x+2))
            {
                medianIndex = x+0;
            }
            else 
            {
                medianIndex = x+2;
            }
        }
    }
    return medianIndex;
}
