#include <stdio.h>
void swap(int *a, int *b);
int main() {
    int n;
    scanf("%d", &n);

    int x[n];
    int *p;

    for(p = x; p < x+n; p++) scanf("%d", p);

    int a, b;
    scanf("%d %d", &a, &b);

    swap(x+a, x+b);

    for(p = x; p < x+n; p++) printf(" %d", *p);
    printf("\n");

    return 0;
}

void swap(int *a, int *b){
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
