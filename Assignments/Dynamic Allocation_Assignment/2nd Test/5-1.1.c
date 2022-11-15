#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str[250+1];
    char b[10+1], c[10+1];

    gets(str);
    gets(b);
    gets(c);
    int len = strlen(str);
    char *p;
    for(p = str; *p && p < str + len; p++){
        if(strncmp(p,b,strlen(b)) == 0){
            // puts("dbg... if statement is pushed!\n");
            *(str + len + strlen(c)) = '\0';
            for(char *t = str+len-1; t >= p+strlen(c)-strlen(b) ;t--) *(t+strlen(c)) = *t;
            // puts(str);
            for(int i = 0; i< strlen(c); i++) *(p+i) = *(c+i);
            // puts(str);
            len += strlen(c) - strlen(b);
        }
    }
}