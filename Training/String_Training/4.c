#include <stdio.h>

int main() {
    char string1[101], string2[101];
    char *p;
    int length;

    scanf("%s", string1);
    scanf("%s", string2);

    length=0;
    for(p = string1; ; p++){
        if(*p == '\0') break;
        length++;
    }
    printf("%d ", length);

    for(int i = 0; i < length ; i++){
        if(string1[i]!=string2[i]) {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}

// clean code?