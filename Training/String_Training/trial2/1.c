#include <stdio.h>

int main() {
    char str[20+1];

    scanf("%s", str);

    for(int i = 0; str[i]; i++) {
        if(str[i]>='a'&& str[i]<='z') printf("%c", str[i]);
    }
    return 0;
}