#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct st {
    char *str;
    int cnt1;
    int cnt2;
    int num;
    int pos;
    int result;
} st;

int main(){
    // 1
    int n;
    scanf("%d", &n);
    getchar();

    st *p = (st *) malloc(n*sizeof(st));
    if(p == NULL) {
        return -1;
    }

    int i;
    char tmp[100+1];

    for(i= 0; i< n; i++) {
        gets(tmp);
        (p+i)->str = (char *) malloc((strlen(tmp)+1) * sizeof(char));
        strcpy((p+i)->str, tmp);
    }

    // 2
    for(i = 0;i <n ;i++) {
        char *c;
        for(c = (p+i)->str; *c; c++) {
            ((p+i)->cnt2) ++;
            // number finding : break if number has founded.
            if(*c >= '0' && *c <= '9'){
                (p+i)->num = *c - '0';
                (p+i)->pos = c - (p+i)->str +1;
                continue;
            }
            if(*c!='A' && *c!='a' && 
            *c!='E' && *c!='e' && 
            *c!='I' && *c!='i' && 
            *c!='O' && *c!='o' && 
            *c!='U' && *c!='u'){
                ((p+i)->cnt1)++;
            }
        }

        (p+i)->result = (p+i)->cnt1 *(p+i)->cnt2 * (p+i)->num * (p+i)->pos;

        

        // printf("---2 : %s %d %d %d %d %d\n", (p+i)->str, (p+i)->cnt1, (p+i)->cnt2, (p+i)->num, (p+i)->pos, (p+i)->result);
    }

    // 3
    int j;
    for(i = 0;i < n;i++) {
        for(j = 1; j<n; j++){
            if( (p+j-1)->result < (p+j)->result ){
                st newst;
                newst = *(p+j-1);
                *(p+j-1) = *(p+j);
                *(p+j) = newst;
            }
        }
    }

    for(i = 0;i <n; i++) puts((p+i)->str);

    for(i = 0; i< n; i++) free((p+i)->str);
    free(p);
}

/*
5
His0tory
3Politics
2DonQuixote
LaPest9e
Chaos5
*/