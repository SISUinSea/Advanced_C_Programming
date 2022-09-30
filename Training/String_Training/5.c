#include <stdio.h>

int main() {
    int insert;
    char str1[40+1], str2[20+1];
    char *p;

    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &insert);

    for(p = str1+insert; p < str1+insert+insert; p++ ){
        *(p+insert) = *p;
    }
    for()
    return 0;
}


