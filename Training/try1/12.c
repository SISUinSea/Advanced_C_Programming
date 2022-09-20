#include <stdio.h>
void addArray(int *a, int *b, int *c, int n);
int main() {
    int n;
    scanf("%d",&n);

    int a[n], b[n], c[n];
    int *p;

    for(p = a; p<a+n;p++) scanf("%d", p);
    for(p = b; p<b+n;p++) scanf("%d", p);



    addArray(a, b, c, n);

    for(p = c; p<c+n;p++) printf(" %d", *p);
    return 0;
}

void addArray(int *a, int *b, int *c, int n){
    int *pa, *pb, *pc;

    for(pa = a, pb = b+n -1, pc = c; pa < a + n; pa++, pb--, pc++)
    {
        *pc = *pb + *pa;
    }

}
