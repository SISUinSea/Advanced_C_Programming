#include <stdio.h>
#include <string.h>

int main() {
    char str1[80+1], str2[10+1];
    scanf("%s", str1);
    getchar();
    scanf("%s", str2);

  

    char *p, *p2, *p1;
    int len1, len2, isSame,count=0;
    len1 = strlen(str1);
    len2 = strlen(str2);

    printf("%d ",len1);
    for(p = str1; p <= str1 + len1 - len2; p++){
        isSame = 1;
        for(p2 = str2, p1 = p; p2 < str2 + len2; p2 ++, p1++){
            if(*p2 != *p1) {
                isSame = 0;
                break;
            }
        }
        if(isSame == 1) count ++;
    }
    printf("%d\n", count);
    return 0;
}