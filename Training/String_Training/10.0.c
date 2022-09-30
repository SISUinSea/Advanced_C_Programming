#include <stdio.h>
#include <string.h>

int main() {
    int n, len;
    scanf("%d", &n);
    char str[100+1];
    // gets(str);
    // puts(str);
    int min = 100;
    char minstr[100+1];
    for(int i = 0; i < n+1; i++){

        printf("%d loop is start\n", i);
        fgets(str, 100, stdin);
        len=strlen(str);
        puts(str);
        if(len < min){
            min = len;
            strcpy(minstr, str);
        }
    puts(minstr);
    }


    return 0;
}