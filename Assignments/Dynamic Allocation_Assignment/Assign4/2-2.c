#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[100+1], str2[100+1];
    gets(str1);
    gets(str2);

    char *p;
    int cnt=0;
    for(p = str1; *p; p++) if(*p == ' ') cnt++;
    char ** word1 = (char **) malloc((cnt+1)*sizeof(char *));
    if(!word1) {return -1;}
    cnt=0;
    for(p = str2; *p; p++) if(*p == ' ') cnt++;
    char ** word2 = (char **) malloc((cnt+1)*sizeof(char *));
    if(!word1) {return -1;}



    int wi1=0, wi2=0;
    cnt=0;
    for(p = str1; *p; p++){
        if(*p != ' ') {
            cnt++;
        }else {
            word1[wi1] = (char *) malloc((cnt+1)*sizeof(char));
            if(!word1[wi1]) return -1;
            strncpy(word1[wi1++], p-cnt, cnt);
            cnt=0; 
        }
    }
            word1[wi1] = (char *) malloc((cnt+1)*sizeof(char));
            if(!word1[wi1]) return -1;
            strncpy(word1[wi1++], p-cnt, cnt);
            cnt=0;
    for(p = str2; *p; p++){
        if(*p != ' ') {
            cnt++;
        }else {
            word2[wi2] = (char *) malloc((cnt+1)*sizeof(char));
            if(!word2[wi2]) return -1;
            strncpy(word2[wi2++], p-cnt, cnt);
            cnt=0; 
        }
    }
            word2[wi2] = (char *) malloc((cnt+1)*sizeof(char));
            if(!word2[wi2]) return -1;
            strncpy(word2[wi2++], p-cnt, cnt);


    // for(int i =0; i<wi1; i++) puts(word1[i]);
    // for(int i =0; i<wi2; i++) puts(word2[i]);

//2
    char **result = (char**)malloc(1*sizeof(char*));
    int ri=0;
    if(!result) {return -1;}
    for(int i=0; i<wi1; i++){
        for(int j =0;j<wi2; j++){
            if(strcmp(word2[j], word1[i]) == 0 ){
                result[ri] = (char*)malloc((strlen(word1[i])+1)*sizeof(char));   
                if(!result[ri]){return -1;}
                strcpy(result[ri++], word1[i]);
                result = (char **) realloc(result, (ri+1)*sizeof(char*));
                break;
            }
        }
    }

    int i, j;
    for(i =0; i<ri; i++){
        for(j=1;j<ri;j++){
            if(strlen(result[j-1]) < strlen(result[j]) ||
            strlen(result[j-1]) == strlen(result[j]) && strcmp(result[j-1], result[j]) > 0
            ){
                char *tmp;
                tmp = result[j-1];
                result[j-1] = result[j];
                result[j] = tmp;
            }
        }
    }

    for(int i =0;i <ri; i++) puts(result[i]);

}

/*
red orange yellow green blue purple
pink red yellow black white purple
*/