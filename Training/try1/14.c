#include <stdio.h>
int add_to_k(int *a, int *b);

int main() {
    int n, total = 0;
    scanf("%d", &n);

    int x[n];
    int *p, *i;

    for(p = x; p < x+n; p++) scanf("%d", p);

    for(p = x; p < x+n; p++){
        total += add_to_k(x,p);
    }

    printf("%d\n", total);
    return 0;
}

int add_to_k(int *a, int *b){
    int total = 0;
    int *p;

    for(p = a; p <= b; p ++)
    {
        total += *p;
    }

    return total;
}
