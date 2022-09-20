#include <stdio.h>
#include <string.h>

int main(){
    char ch[20];
    char *p, *index;

    scanf("%s", fch);

    for(p = ch; p < ch + strlen(ch); p++)    {
        if(*p == '#'){
            index = p;
             break;
        }
    }

    for(p = index-1; p >= ch; p--){
        printf("%c", *p);
    }
    
    return 0;
}