#include <stdio.h>
int input(int *p);
int *sel_next(int *p);
int number(int *p , int *q);
int main() {
    int arr[100], size, *last = arr, *first = arr, *p;
    size = input(arr);
    // printf("dbg ... %d\n", size);

    for(p = arr; *p != -1; p++){
        last = sel_next(last);
        if(first != last)
            printf("%d\n", number(first, last));
        first = last;
    }
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
int *sel_next(int *arr ){
    int *p;

    if(*(arr) < *(arr+1)){
        // printf("dbg: if block entered\n");

        for(p = arr+1; *p != -1; p++){
            if(*(p-1) >= *p) {
                break;
            }
        }
    }   

    else {
        // printf("dbg: else block entered\n");
        for(p = arr+1; *p != -1; p++){
        if(*(p-1) <= *p) {
            break;
        }
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
