#include <stdio.h>
#include <stdlib.h>


int *sizeUP(int arr[], int s);
int main(){
    // int* p = (int *) malloc(3*sizeof(int));
    // p[0] = 12;
    // p[1] = 34;
    // p[2] = 56;

    // p = sizeUP(p, 3, 1);

    // for(int i = 0; i<4; i++) printf(" %d", p[i]);
    int *p = (int *) malloc(5*sizeof(int));
    int i = 0, len=5;
    while(1){
        scanf("%d", p+i);
        if(p[i] == -1)break;
        if(i == len-1) {
            p =(int*) sizeUP(p, len);
            len+=3;
        }
        // printf("%d dbg... still in while loop, p[i] is %d\n", i, p[i]);
        i++;
    }

    for(i = 0; i<len; i++) {
        printf(" %d", p[i]);
        if(p[i] == -1) break;
    }
}

int *sizeUP(int arr[], int s){
    int *result = (int *) malloc((3+s)*sizeof(int));
    for(int i = 0; i<s; i++) result[i] = arr[i];
    // for(int i = s; i<3+s; i++) {
    //     scanf("%d", &result[i]);
    //     printf("still in sizeUP method...%d \n ", result[i]);
    // }

    return result;
}
/*
3 4 5 6 7 8 9 -1
*/