#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, len, n;
    scanf("%d", &n); getchar();

    char tmp[100+1];
    char **p = (char**) malloc(n*sizeof(char*));

    if(p == NULL) return -1;

    for(i=0; i<n; i++) {
        gets(tmp);
        len= strlen(tmp);
        p[i] = (char*) malloc((len+1)*sizeof(char));
        if(p[i] == NULL) return 0;
        strcpy(p[i], tmp);
    }

    for(i = 0; i<n;i++) puts(p[i]);
    for(i = 0; i<n; i++) free(p[i]);
    free(p);
}