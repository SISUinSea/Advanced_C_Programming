#include <stdio.h>
int is_atoz (char c);
int main() {
    char str[21];

    scanf("%s", str);

    // for(int i = 0; str[i] != NULL; i++){
    for(int i = 0; str[i]; i++){

        if(is_atoz(str[i])) printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
int is_atoz (char c){
    if(c >= 'a' && c <= 'z') return 1;
    else return 0;
}
