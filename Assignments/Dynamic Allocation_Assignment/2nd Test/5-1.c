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
    int blen = strlen(b);
    char *ap;
    char t[100+1];
    for(int i = 0; i<wi; i++) {
        for(ap = word[i]; *ap; ap++){
            if(strncmp(b, ap, blen) == 0){
                // strcpy(t, ap);

                // strncpy(ap, t, )
                // strcat(ap, c);
                // strcat(ap, t+blen);
                
                    printf("dbg2 ---");
                puts(ap);
                ap+=blen-1;
            }
        }
    }
}

/*
I have a pen. I have an applepen. PPAP.
*/