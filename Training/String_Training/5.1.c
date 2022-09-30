#include <stdio.h>

int main() {
    char str1[41], str2[21];
    scanf("%s", str1);
    scanf("%s", str2);

    int insertIndex;
    scanf("%d", &insertIndex);

    int str1length, str2length;
    str1length = str2length = 0;

// str1length
    for(int i = 0; ; i++){
        if(str1[i] == '\0') break;
        str1length++;
    }
// str2length
    for(int i = 0; ; i++){
        if(str2[i] == '\0') break;
        str2length++;
    }
    return 0;
}