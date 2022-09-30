#include <stdio.h>
#include <string.h>

int main() {
    char str1[100+1], str2[100+1];
    gets(str1);
    gets(str2);

    int len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);

    char *p, *p1, *p2;
    int count = 0, isSame;

    for(p = str1; p <= str1 + len1 - len2;isSame == 1? p+=len2 : p++){
        isSame = 1;
        for(p1= p, p2 = str2; p2 < str2 + len2; p2++, p1++){
            if(*p1 != *p2) {
                isSame = 0;
                break;
            }
        }
        if(isSame== 1) count++;
    }
    printf("%d\n",count);

    return 0;
}