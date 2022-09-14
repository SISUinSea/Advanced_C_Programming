#include <stdio.h>

void strcopy(char *a, char *b);

int main(){
    char a[6], b[6];
    char *p;

    for(p = a; p < a + 6 ; p++){
        scanf("%c", p);
    }
    
    strcopy(a, b);

    for(p = b; p < b + 6; p++){
        printf("%c", *p);
    }
    return 0;
}

void strcopy(char *a, char *b){
    char *p, *p2;
    for(p = a, p2 = b; p < a + 6; p++, p2++){
        *p2 = *p;
    }
}
