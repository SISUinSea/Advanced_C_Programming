/*
CLikp5tGLE?Qej15J
2
*/
#include <stdio.h>
#include <stdlib.h>
void decoder(char *a, char *b, int n);
char capital(char c, int n);
char small(char c, int n);
int toInt(char *c);
int main(){
    char a[20+1];
    char b[30+1];
    int n;
    gets(a);
    scanf("%d", &n);
    // getchar();
    // printf("%d", toInt(a));
    decoder(a, b, n);
    puts(b);
    return 0;
}

void decoder(char *a, char *b, int n){
    int i=0,j;
    char *p;
    for(p = a; *p ; p++){
        if(*p >='A'&& *p <='Z'){
            *(b+i++) = capital(*p,n);
        }
        else if(*p >= 'a' && *p <= 'z'){
            *(b+i++) = small(*p,n);
        }else if(*p >= '0' && *p <='9'){
            if(*(p-1) >= '0' && *(p-1) <='9') continue;
            char result = 'A' + toInt(p) - 1;
            for(j = 0; j < n;j++) 
                *(b+i++) = result;
        }else { // *p == ., !, ?, ...
            *(b+i++) = ' ';
        }
    }
    *(b+i) = '\0';
}

char capital(char c, int n){
    return (c - 'A' + n)%26 + 'A';
    // return c + n;
 }
char small(char c, int n){
    return (c - 'a' - n)%26 + 'a';
}

int toInt(char *c){
    // printf("c+1 is ...%c", *(c+1));
    char tmp = *c;
    int result = atoi(&tmp);
    // printf("result is ...%d\n", result);
    if(*(c+1) >= '0' && *(c+1) <= '9'){
        result*=10;
        result += atoi(c+1);
    }
    return result;
}
