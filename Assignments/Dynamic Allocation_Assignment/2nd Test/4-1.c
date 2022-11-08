/*
1 2 3 4 5 4 3 -1
*/

#include <stdio.h>
int input(int *p);
int *sel_next(int *p, int n, int m);
int number(int *p , int *q);
int main(){
    int arr[100], size, m, *last;
    size = input(arr);
    // printf("dbg ... %d\n", size);
    scanf("%d", &m);
    last = sel_next(arr, size, m);

    printf("%d\n", number(arr+m, last));

}

int input(int *p){
    int size = 0;
    int i;
    for(size = 0; ; size++){
        scanf("%d", p+size);
        if(*(p+size)==-1) break;
    }
    return size;
}
int *sel_next(int *arr, int n, int m){
    int *p;
    for(p = arr+m+1; p < arr+n; p++){
        if(*(p-1) >= *p) {

            break;
        }
    }

    return p-1;
}
int number(int *s , int *e){
    int result = 0;
    int *p;
    for(p = s; p <= e; p++){
        result += *p;
        result*=10;
    }result/=10;

    return result;
}
