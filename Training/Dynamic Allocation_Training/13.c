#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;scanf("%d", &n);
    int*p = (int *)malloc(n*sizeof(int));

    int i;
    for(i = 0; i<n; i++) scanf("%d", p+i);

    int d;
    scanf("%d", &d);

    p = realloc(p, (n-d)*sizeof(int));

    for(i=0; i<n-d; i++) printf("%d\n", p[i]);
    free(p);
}