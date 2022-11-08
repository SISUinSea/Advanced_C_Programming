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
    int n;
    scanf("%d", &n);
    getchar();

    char tmp[100+1];
    st *p = (st *) malloc(n*sizeof(st));
    if(p == NULL){
        printf("1 memory allocation error\n");
        return -1;
    }

    int i;
    for(i = 0; i <n; i++) {
        gets(tmp);
        (p+i)->str = (char *) malloc( (strlen(tmp)+1) * (sizeof(char)) );
        if((p+i)->str == NULL) {
            printf("memory allocation error\n");
            return -1;
        }
        strcpy((p+i)->str, tmp);
    }

    char *cp;
    for(i = 0; i<n; i++){
        (p+i)->cnt2 = strlen((p+i)->str);
        for(cp = (p+i)->str; *cp; cp++){
            if(*cp != 'a' && *cp != 'e' && *cp != 'i' && *cp != 'o' && *cp != 'u'
            && *cp != 'A' && *cp != 'E' && *cp != 'I' && *cp != 'O' && *cp != 'U'
            ){
                (p+i)->cnt1++;
            }
            if(*cp >='0' && *cp<='9'){
                (p+i)->pos = cp - (p+i)->str +1;
                (p+i)->num = *cp - '0';
            }
        }
        (p+i)->result = (p+i)->num *  (p+i)->pos * (p+i)->cnt1 * (p+i)->cnt2;
    }

    int j= 0;
    st tmpST;
    for(i = 0; i<n; i++){
        for(j = 1; j<n; j++){
            if((p+j-1)->result < (p+j)->result) {
                tmpST = *(p+j-1);
                *(p+j-1) = *(p+j);
                *(p+j) = tmpST; 
            }
        }
    }

    for(i = 0; i<n; i++) puts((p+i)->str);
    // printf("%s %d\n",(p+i)->str, (p+i)->result);

    for(i = 0; i<n; i++) free((p+i)->str);
    free(p);
}