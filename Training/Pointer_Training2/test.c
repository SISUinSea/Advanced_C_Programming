#include <stdio.h>

int main(){
    char str1[41] = {0}, str2[21] = {0};
    int index = 0, len1 = 0, len2 = 0, reverse;

    scanf("%s", str1);
    scanf("%s", str2);

    scanf("%d", &index);
    scanf("%d", &reverse);

    for(len1 = 0; str1[len1]; len1++);
    for(len2 = 0; str2[len2]; len2++);

    for(int i= 0; i < len1 - index ; i++){
        str1[len1 +len2 -i-1] = str1[len1 - i -1];

    }

    if(!reverse){
    for(int i = 0; i < len2 ; i++)
        str1[index+i] = str2[i];    
    }
    
    else {
        for(int i = 0; i < len2 ; i++)
            str1[index+i] = str2[len2-i-1];
    }
    
    printf("%s", str1);

    return 0;

}