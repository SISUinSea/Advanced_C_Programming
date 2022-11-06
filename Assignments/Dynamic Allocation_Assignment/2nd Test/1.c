#include <stdio.h>
#include <string.h>

int main(){
    char str[200+1], tmp[200+1];
    char word[20][200+1];
    int wi=0, wj=0;
    int i;

    gets(str);
    for(i=0;str[i]; i++) {
        if(str[i]!=' ') {
            word[wi][wj++] = str[i];
        }else {
            word[wi++][wj] = '\0';
            puts(word[wi-1]);
            wj=0;
        }
    }
    word[wi++][wj] = '\0';
    puts(word[wi-1]);

    int j;
    for(i =0; i<wi; i++){
        for(j=1; j<wi; j++){
            if(strcmp(word[j-1], word[j]) > 0) {
                strcpy(tmp, word[j]);
                strcpy(word[j], word[j-1]);
                strcpy(word[j-1], tmp);
            }
        }
    }

    for(i=0; i<wi; i++) printf("%s ", word[i]);
    printf("\n");
}