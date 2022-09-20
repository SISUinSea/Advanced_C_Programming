#include <stdio.h>
int arrsum(int *s, int *e);
int main() {
    int n,s,e;
    scanf("%d %d %d", &n, &s, &e);

    int x[n];
    int *p;

    for(p = x; p < x+n; p++) scanf("%d", p);


    printf("%d\n", arrsum(x+s, x+e));
    return 0;
}

int arrsum(int *s, int *e){
    int total = 0;
    int *p;

    for(p = s; p <= e; p++)  total += *p;

    return total;
}
