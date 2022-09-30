#include <stdio.h>
#include <string.h>

int main() {
    int n;scanf("%d",&n);
    getchar();

    int min = 100, len;
    char minstr[100+1];
    
    for(int i = 0; i < n; i++){
        char str[100+1];
        gets(str);
        len = strlen(str);
        if(min > len){
            min = len;
            strcpy(minstr, str);
        }
    }

    puts(minstr);
    return 0;
}