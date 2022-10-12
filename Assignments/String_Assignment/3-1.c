#include <stdio.h>
#include <string.h>
int main(){
    char str1[100], str2[100];
    gets(str1);
    gets(str2);
    int i, j,k, isSame, count=0;
    for(i = 0; str1[i]; i++){
        isSame = 1;
        for(j = i, k = 0; str1[j]&&str2[k]; j++, k++){
            if(str1[j]!= str2[k]){
                isSame = 0;
                break;
            }
        }
        if(isSame) {
            count ++;
        }
    }
    printf("%d\n", count);
    return 0;
}

/*
I have a pen. I have an applepen. PPAP.
pen
*/