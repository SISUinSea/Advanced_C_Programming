#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100+1];
    gets(str);
    char *p;
    int cnt=0;
    for(p = str; *p; p++) if(*p == ' ') cnt++;
    char ** word = (char **) malloc((cnt+1)*sizeof(char *));

    int wi=0;
    cnt=0;
    for(p = str; *p; p++){
        if(*p != ' ') {
            cnt++;
        }else {
            word[wi] = (char *) malloc((cnt+1)*sizeof(char));
            if(!word[wi]) return -1;
            strncpy(word[wi++], p-cnt, cnt);
            cnt=0; 
        }
    }
            word[wi] = (char *) malloc((cnt+1)*sizeof(char));
            if(!word[wi]) return -1;
            strncpy(word[wi++], p-cnt, cnt);

// 2
    int i, j;
    for(i =0; i<wi; i++){
        for(j=1;j<wi;j++){
            if(strlen(word[j-1]) < strlen(word[j]) ||
            strlen(word[j-1]) == strlen(word[j]) && strcmp(word[j-1], word[j]) > 0
            ){
                char *tmp;
                tmp = word[j-1];
                word[j-1] = word[j];
                word[j] = tmp;
            }
        }
    }
    for(int i =0; i<wi; i++) puts(word[i]);
}

/*
red orange yellow green blue purple
*/