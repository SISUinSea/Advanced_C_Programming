#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *p = NULL;
    p = (int *) malloc(n*sizeof(int));

    int i;
    for(i = 0; i<n; i++) scanf("%d", p+i);

    int sum = 0;
    for(i = 0; i<n; i++) sum+=*(p+i);

    printf("%d\n", sum);
    
    return 0;
}