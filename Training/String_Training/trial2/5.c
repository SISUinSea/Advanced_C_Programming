#include <stdio.h>

int main() {
    char str[100+1], str1[100+1];
    gets(str);
    gets(str1);

    int isSame = 1;
    int len;
    for(len = 0; str[len]; len++) ;

    for(int i = 0; i < len; i++){
        if(str[i]!=str1[i]){
            isSame = 0;
            break;
        }
    }

    printf("%d %d\n", len, isSame);
    return 0;
}