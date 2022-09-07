#include <stdio.h>

int main(){
    int arr[5]={0,}, rank[5]={1,1,1,1,1};
    int *p, *rankPointer, *arrPointer;

    for(p = arr; p < arr +5; p++) scanf("%d", p);
// for(p = arr; p < arr +5; p++) printf("%d", *p);

    for(arrPointer = arr, rankPointer = rank; arrPointer < arr + 5; arrPointer++, rankPointer++){
        for(p = arr; p < arr + 5; p++)
            if(*arrPointer < *p) (*rankPointer)++;
    }

     for(arrPointer = arr, rankPointer = rank; arrPointer < arr + 5; arrPointer++, rankPointer++){
        printf("%d=r%d ",*arrPointer,*rankPointer);
     }
    return 0;
}