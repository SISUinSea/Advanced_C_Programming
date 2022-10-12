#include <stdio.h>

int main() {
    int insert, i, len1, len2, reverse;
    char str1[40+1], str2[20+1];
    gets(str1);
    gets(str2);
    scanf("%d", &insert);
    scanf("%d", &reverse);

    for(len1 = 0; str1[len1]; len1++);
    for(len2 = 0; str2[len2]; len2++);

    for(i = len1 - 1; i >= insert; i--) 
        str1[i + len2] = str1[i];
    if(!reverse)
    for(i = 0; i < len2 ; i++) {
        str1[i+insert] = str2[i];
    }
    else {
        for(i = 0; i < len2; i++){
            str1[i+insert] = str2[len2-1-i];
        }
    }

    // for(i = insert; i < len1; i++){
    //     str1[i+len2] = str1[i];
    //     printf("%s\n", str1);
    // }
    // for(i = 0; i < len2; i++){
    //     str1[i+insert] = str2[i];
    // }
    printf("%s\n", str1);

    return 0;
}