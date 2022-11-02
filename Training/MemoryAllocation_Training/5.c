#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *p = NULL;
    p = (int *) malloc(n*sizeof(int));

    int i;
    for(i = 0; i<n; i++) scanf("%d",p+i);

    int tmp;
    for(i=1; i<n;i++){
        if(*(p+i-1) > *(p+i)){
            tmp = *(p+i);
            *(p+i) = *(p+i-1);
            *(p+i-1) = tmp;
        }
    }

    for(i = 0; i<n; i++) printf("%d\n", *(p+i));
    return 0;
}