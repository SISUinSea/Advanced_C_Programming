#include <stdio.h>
void swap(int *a, int *b);
int main(){
    int n; scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);

    int a, b; scanf("%d %d", &a, &b);

    swap(x+a, x+b);

    for (int i = 0; i < n; i++) printf(" %d", x[i]);
    
    return 0;
}
void swap(int *a, int *b) {
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}
