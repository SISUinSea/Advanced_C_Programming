#include <stdio.h>
void strcopy(char a[], char b[]);
int main() {
    char a[6], b[6];
    char *p;
    
    for(p = a; p < a+6; p++) scanf("%c", p);

    // for(p = a; p < a+6; p++) printf("%c",*p);

    strcopy(a, b);

    for(p = b; p < b+6; p++) printf("%c",*p);


    return 0;
}
void strcopy(char a[], char b[]){
    char *pa, *pb;

    for(pa = a, pb = b; pa < a +6; pa++, pb++){
        *pb = *pa;
    }
}
