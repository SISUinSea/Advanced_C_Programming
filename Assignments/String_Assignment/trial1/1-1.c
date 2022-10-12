#include <stdio.h>
void decoder(char *str, char *strRersult, int n);
char capital(char *c, int n);
char small(char *c, int n);
char integer(char *c);
char other(char *c);
int main(){
    int n;
    char str[20+1];
    char strResult[20+1];
    scanf("%d", &n);
    getchar();
    gets(str);
    // done.

    // decoder(str, strResult, n);
    // puts(str);

// debuging code zone.
    // printf("%c", capital(str,n));

    return 0;
}

void decoder(char *str, char *strResult, int n){
    char *p;
    int i = 0;
    for(p = str; *p; p++){
        // CAPITAL ALPHABEt
        if(*p >= 'A' && *p <='Z'){
            // *(strResult+i++) = 
        }
        // small alphabet
        else if(*p>='a'&& *p<='z'){

        }
        // number
        else if(*p>='0'&& *p<='9'){

        }// other else
        else{

        }
        
    }
}

char capital(char *c, int n){
    return *c + n;
}

char small(char *c, int n){
    return *c - n;
}

char integer(char *c){
    
}