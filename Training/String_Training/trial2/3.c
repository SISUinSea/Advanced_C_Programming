#include <stdio.h>

int main() {
    char str[100+1], tmp;
    int i, j;
    scanf("%s", str);

    for(i = 0; str[i]; i++){
        printf("%s\n", str);
            tmp = str[0];
        for(j = 1; str[j];j++){
            str[j-1]= str[j];
        }
        str[--j] = tmp;
    }
    return 0;
}