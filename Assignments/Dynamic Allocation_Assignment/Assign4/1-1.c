#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct st {
    char *str;
    int cnt1;
    int cnt2;
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
            if(*c!='A' && *c!='a' && 
            *c!='E' && *c!='e' && 
            *c!='I' && *c!='i' && 
            *c!='O' && *c!='o' && 
            *c!='U' && *c!='u'){
                ((p+i)->cnt1)++;
            }
            ((p+i)->cnt2)++;
        }

        // printf("---2 : %s %d %d\n", (p+i)->str, (p+i)->cnt1, (p+i)->cnt2);
    }

    // 3
    int j;
    for(i = 0;i < n;i++) {
        for(j = 1; j<n; j++){
            if( (p+j-1)->cnt1 < (p+j)->cnt1 || 
            (p+j-1)->cnt1 == (p+j)->cnt1 && (p+j-1)->cnt2 < (p+j)->cnt2){
                st newst;
                newst = *(p+j-1);
                *(p+j-1) = *(p+j);
                *(p+j) = newst;
            }
        }
    }

    for(i = 0;i <n; i++) puts((p+i)->str);
}

/*
5
History
Politics
DonQuixote
LaPeste
Chaos
*/