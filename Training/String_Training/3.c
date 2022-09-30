#include <stdio.h>

int main() {
    int length;
    char string[101], tmp;
    char *p;
    scanf("%s", string);

    length = 0;
    for(p = string; ; p++){
        if(*p == '\0') break;
        length ++;
    }
    for(int i = 0; i < length-1 ; i++){
    printf("%s", string);
        tmp = *string;
        for(p = string+1; p < string+length; p++){
            *(p-1) = *p;
        }
        *(string+length-1) = tmp;

    }
    // printf("%s", string);
    // for(int i = 0; i < length-1 ; i++){
    //     tmp = *string;
    //     for(p = string+1; p < string+length; p++){
    //         *(p-1) = *p;
    //     }
    //     *(string+length-1) = tmp;
    //     printf("%s\n", string);
    // }
    return 0;
}