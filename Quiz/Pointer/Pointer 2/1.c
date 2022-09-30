#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char str1[n+1], str2[m+1];
    scanf("%s", str1);
    scanf("%s", str2);

    char *p, *p1, *p2;
    int count = 0, isSame;
    for(p = str1; *p ; p++){
        isSame = 1;
        for(p1 = p, p2 = str2; *p2 ; p2++, p1++){
            if(*p1 != *p2){
                isSame = 0;
                break;
            }
        }
        if(isSame == 1) count++;
    }

    printf("%d", count);
    return 0;
}