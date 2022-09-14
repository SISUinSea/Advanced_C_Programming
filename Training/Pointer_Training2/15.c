#include <stdio.h>
void ABC(int *s, int k);
int main() {


    int arr[10], i;
    int *p;

    for(p = arr; p < arr + 10; p++)
    {
        scanf("%d", p);
    }

    for(p = arr, i = 10; p < arr + 9; p++, i--)
    {
        ABC(p,i);
    }
        for(p = arr; p < arr+10; p++) printf(" %d", *p);
        printf("\n");

    
    return 0;
}

void ABC(int *s, int k){
    int max = *s, tmp;
    int *maxindex = s, *p; // tmp

    for(p = s; p < s + k ; p++) 
    {
        if(max < *p)
        {
            max = *p;
            maxindex = p;
        }
    }

    tmp = *s;
    *s = max;
    *maxindex = tmp;
}

