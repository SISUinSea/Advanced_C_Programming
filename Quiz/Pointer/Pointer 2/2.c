#include <stdio.h>
void sorting(int *s, int *e, int f);
int main(){
    int arr[10];
    int *p;

    for(p = arr; p < arr+10; p++) scanf("%d", p);
    // for(p = arr; p < arr+10; p++) printf("%d ", *p);


    int s, e, f;


    while (1)
    {
        scanf("%d", &s);
        if(s == -1) return 0;
        scanf("%d %d", &e, &f);
        sorting(arr+s, arr+e, f);
        for(p = arr; p < arr + 10; p++) printf("%d ", *p);
        printf("\n");
    }
    

    return 0;
}

void sorting(int *s, int *e, int f){
    int *p, *p1;


    if(f == 0){
        int min, *minP, tmp;
        for(p = s; p <= e; p++){
            min = *p;
            minP = p;
            for(p1 = p; p1 <= e; p1++){
                if(min > *p1){
                    min = *p1;
                    minP = p1;
                }
            }
            tmp = *p;
            *p = min;
            *minP = tmp;
        }
    }
    else {
        int max, *maxP, tmp;
        for(p = s; p <= e; p++){
            max = *p;
            maxP = p;
            for(p1 = p; p1 <= e; p1++){
                if(max < *p1){
                    max = *p1;
                    maxP = p1;
                }
            }
            tmp = *p;
            *p = max;
            *maxP = tmp;
        }
    }

}
