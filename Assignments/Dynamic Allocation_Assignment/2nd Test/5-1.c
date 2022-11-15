#include <stdio.h>
#include <string.h>

int main(){
    //1
    char a[100+1];
    char b[10+1], c[10+1];
    char word[50+1][100+1];
    int wi = 0, wj = 0;

    gets(a);
    gets(b);
    gets(c);

    char *p;
    for(p = a; *p; p++){
        if(*p != ' ' && *p != '.'){
            word[wi][wj] = *p;
            wj++;
        }else {
            if(*(p-1) != ' ' && *(p-1) != '.')
                word[wi++][wj] = '\0';
            wj = 0;
        }
    }
    word[wi++][wj] = '\0';

    // for(p = *word; p < *(word+wi); p++) puts(p);
    // dbg for 1.
    // for(int i = 0; i<wi; i++) printf("dbg1 --- %s\n", word[i]);

    //2 3
    char tmp[100+1];
    int blen = (int)strlen(b);
    for(int i = 0;i <wi; i++) {
        char *ap;
        for(ap = word[i]; ap < word[i] + strlen(word[i]); ap++){
            if(strncmp(ap, b, blen) == 0){
                strcpy(tmp, "");
                strncpy(tmp, word[i], ap - word[i]);
                strcat(tmp, c);
                // if( strcmp(tmp, "") != 0 )printf("%s : end dbg... \n", tmp);
                strcpy(word[i], "");
                strcat(word[i], tmp);

            }
        }
    }

    for(int i = 0; i<wi; i++ ) puts(word[i]);
}

/*
I have a pen. I have an applepen. PPAP.
pen
mouse
*/