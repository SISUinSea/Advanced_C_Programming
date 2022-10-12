#include <stdio.h>
void decoder(char *str);
char capital(char c, int n);
char small(char c, int n);
void intMaker(char *c, int *d);
int main(){
    // printf("%c",('Z'+2 - 'A')%26 + 'A');
    char str[20+1];
    int n;
    scanf("%s", str);
    scanf("%d", &n);
    printf("%s", str);
    // printf("%c", small(str[0], n));

    return 0;
}

/*
CLikp5tGLE?Qej15J
*/

char capital(char c, int n){
    return (c + n - 'A')% 26 + 'A';
}
char small(char c, int n){
    return (c + n - 'a')%26 + 'a';
}
void intMaker(char *c, int *d){
    if(*(c+1) >= )
}