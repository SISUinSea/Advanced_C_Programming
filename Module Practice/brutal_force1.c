// string 두 개를 받아서 두 번째 string이 첫 번째 string 에 얼마나 포함되어 있는지

#include <stdio.h>
#include <string.h>

int main() {
    int count = 0;
    int i, j, k;
    int isSame;
    char str1[100+1], str2[100+1];

    gets(str1);
    gets(str2);

    for(i = 0; str1[i];isSame == 1 ? i+=strlen(str2): i++){
        isSame = 1;
        for(j = 0, k = i; str2[j]; j++, k++){
            if(str1[k] != str2[j]){
                isSame = 0;
                break;
            }
        }
        if(isSame == 1){
            count++;
        }
    }

    printf("%d\n", count);
}