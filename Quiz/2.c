#include <stdio.h>
void sorting(int *s, int *e, int f);
int main() {
    int ar[10];
    int i;
    for(i = 0; i < 10; i++)scanf("%d", ar+i);
    // for(i = 0; i < 10; i++)printf("%d ", ar"[i]);

    int s, e, f;

    while (1)
    {
        scanf("%d", &s);
        if(s == -1) return 0;
        scanf("%d", &e);
        scanf("%d", &f);
        sorting(ar+s,ar+e,f);
        for(i = 0; i < 10 ; i ++) printf("%d ", ar[i]);
        printf("\n");
    }
    
    
     


    return 0;
}

/*
0 1 2 3 4 5 6 7 8 9
*/

void sorting(int *s, int *e, int f){
    int *p, *p1;

    if(f== 1){
    for(p = s; p <= e; p++){
    int max = *p,*maxindex = p, tmp;
        for(p1 = p; p1 <= e; p1++){
            if(max < *p1) {
                max = *p1;
                maxindex = p1;
            }
        }
        tmp = *p;
        *p = max;
        *maxindex = tmp;
        

    }
    
    }
    else{
        for(p = s; p <= e; p++){
        int min = *p,*minindex = p, tmp;
        for(p1 = p; p1 <= e; p1++){
            if(min > *p1) {
                min = *p1;
                minindex = p1;
            }
        }
        
        tmp = *p;
        *p = min;
        *minindex = tmp;

    }   
    
    }
}
