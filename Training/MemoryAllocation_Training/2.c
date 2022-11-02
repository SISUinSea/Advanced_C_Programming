#include <stdio.h>
#include <stdlib.h>

int main(){
     int n;
     scanf("%d", &n);


    if(n == 0) return 0;
     float *p = NULL;
     p = (float *) malloc(n*sizeof(float));

     int i = 0;
     for(i = 0; i<n;i++) scanf("%f", p+i);

     float max = -99;
     for(i=0; i<n; i++) {
        if(max < *(p+i)){
            max = *(p+i);
            // printf("dbg: %.1f : current max is %.1f\n",*(p+i), max);
        }
     }

     printf("%.2f\n", max);
    return 0;
}