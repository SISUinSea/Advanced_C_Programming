#include <stdio.h>

int main() {
    char str1[100+1], str2[100+1], len1 = 0;
    scanf("%s", str1);
    scanf("%s", str2);

    int isSame = 1;
    char *p, *p2;

    for(p = str1; *p; p++) len1++;

    for(p = str1, p2 = str2; *p && *p2; p++, p2++){
        if(*p!=*p2) {
            isSame = 0;
            break;
        }
    }

    printf("%d %d", len1, isSame!=0?1:0);

    return 0;
}