#include <stdio.h>

int main(){
    int ar[10];
    for(int i = 0; i < 10 ; i++) scanf("%d", ar+i);

    int tmp, max, *maxIndex;

    for(int i = 0; i < 10; i++){
        max = ar[i];
        maxIndex = ar+i;

        for(int j = i; j < 10 ; j++){
            if(max < ar[j]){
                max = ar[j];
                maxIndex = ar+j;
            }
        }

        tmp = ar[i];
        ar[i] = max;
        *maxIndex = tmp;
        for(int k = 0 ; k < 10; k++) printf(" %d", ar[k]);
        printf("\n");
    }
    return 0;
}