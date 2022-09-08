#include <stdio.h>
int add_to_k(int* a, int* b);

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], result = 0;
    int *p, *p2;

    for(p = arr; p < arr+n; p++) scanf("%d", p);

    for(p = arr; p < arr+n; p++)
    {
        result += add_to_k(arr, p);
    }

    printf("%d\n", result);
    
    return 0;
}

int add_to_k(int* a, int* b){
    int result = 0;
    int *p;

    for(p = a; p <= b; p++)
    {
        result += *p;
    }
    return result;
}
