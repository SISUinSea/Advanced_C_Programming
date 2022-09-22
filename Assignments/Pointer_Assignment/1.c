#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int ar[100];
    int *p;

    // for loop
    for(p = ar; ; p++){
        scanf("%d", p);
        if(*p == 0) break;
    }
    
    // print test for debugging
    // for(p = ar; ; p++){
    //     if(*p == 0) break;
    //     printf("%d ",*p);
    // }
    return 0;
}