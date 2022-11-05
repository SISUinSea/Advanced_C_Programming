#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int i,j;
    scanf("%d", &n);

    int *arr = (int *) malloc(n*sizeof(int));
    for(i = 0; i<n; i++) arr[i] = i;

    int *arr1 = (int *) malloc((n-1)*sizeof(int));
    for(i = 0, j = 0; i<n-1; i++, j++) {
        if(arr[j]==(n-1)/2) j++;
        arr1[i] = arr[j];
    }

    for(i = 0; i<n-1; i++) printf(" %d", arr1[i]);

    free(arr);
    free(arr1);

    return 0;

}