#include <stdio.h>
void addArray(int n, int *a, int *b, int *result);
int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n], result[n];
    int *p;

    for(p = a; p < a+n; p++) scanf("%d", p);
    for(p = b; p < b+n; p++) scanf("%d", p);

    addArray(n, a, b, result);

    for(p = result; p < result + n; p++)
    {
        printf(" %d", *p);
    }
    return 0;
}
void addArray(int n, int *a, int *b, int *result){
    int *pb, *pa, *pr;
    for(pb=b+n-1, pa=a, pr=result; pa<a+n; pb--, pa ++, pr++)
    {
        *pr = *pb + *pa;
    }
}
