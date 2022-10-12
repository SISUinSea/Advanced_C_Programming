#include <stdio.h>

int main() {
    char str[9];
    int n, i;
    scanf("%d", &n);

    for(i = 0; n>0; n/=10, i++){ // 12
        str[i] = '0'+n%10;
    }
    // str[i] = '\0';
    // for(i = 0; i < 10; i++) printf("%c", str[i]);
    printf("%s\n", str);
    return 0;
}