/*
apple cat king flower horse dog yellow king
alphabet
*/

#include <stdio.h>
#include <string.h>

int main() {
    char string[100+1], word[10+1];
    gets(string);
    gets(word);

    char data[20][100+1];
    int i,j, di, dj;
    di = dj = 0;
    for(i = 0; i < strlen(string); i++){
        if(string[i]!=' '){
            data[di][dj++] = string[i];
        }else {
            data[di++][dj] = '\0';
            dj = 0;
        }
    }
                data[di++][dj] = '\0';

    // for(i=0; i<di; i++) printf("%s\n", data[i]);
    for(i=0; i<di; i++){
        for(j=i+1; j < di; j++){
            if(strcmp(data[i], data[j])==0){
                strcpy(data[j], word);
            }
        }
    }

    for(i = 0; i<di; i++) printf("%s ", data[i]);
    return 0;
}