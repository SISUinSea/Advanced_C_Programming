#include <stdio.h>

int main() {
    char ar[100+1];
    scanf("%s", ar);

    char tmp;
    int i, j;


    for(j = 0; ar[j]; j++){
        printf("%s\n", ar);
        tmp = ar[0];
        for(i = 0+1; ar[i]; i++){
            ar[i-1] = ar[i];
        }
        ar[--i] = tmp;
    }

    return 0;
}