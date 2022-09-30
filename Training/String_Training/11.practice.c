#include <stdio.h>

int main(){
    char str1[80+1], str2[10+1];
    scanf("%s", str1);
    scanf("%s", str2);

    char *p, *p1, *p2;
    int len1, len2, count = 0, isSame = 1;

    for(p = str1; p <= str1 + len1 - len2; p++){
        isSame = 1;
        for(p1 = p, p2 = str2; p2 < str2 + len2; p2++, p1++){
            if(*p1 != *p2) {
                count ++;
            }
        }
    }
    return 0;
}