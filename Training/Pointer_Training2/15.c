#include <stdio.h>
void ABC(int *p, int k);
int main() {
    int arr[10]={0,}, i;
    int *p, *p2;

    for(p = arr; p < arr+10; p++)
    {
        scanf("%d", p);
    }

        // for(p = arr; p < arr + 10; p++) printf(" %d", *p);


    for(p = arr, i = 10; i >= 2; p++, i--)
    {
        ABC(p,i);
        for(p2 = arr; p2 < arr+10; p2++) printf(" %d", *p2);
    }

    for(p = arr; p < arr + 10; p++) printf(" %d", *p);

    return 0;
}
void ABC(int *s, int k){
    int max = *s, tmp;
    int *p, *index;

    for(p = s; p < s+k; p++)
    {
        if(max < *p)
        {
            max = *p;
            index = p;
        }
    }

    tmp = *s;
    *s = max;
    *index = tmp;
    
    
}
