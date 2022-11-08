#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char tmp[100+1];
    char **p = (char **) malloc(n*sizeof(char*));

    int i;
    getchar();
    for(i = 0; i<n; i++) {
        gets(tmp);
        // p[i] = (char *) malloc((strlen(tmp) + 1) * sizeof(char));
        *(p+i) = (char *) malloc((strlen(tmp)+1) * sizeof(char));
        strcpy(p[i], tmp);
    }

    for(i = 0; i<n; i++) puts(p[i]);
    for(i = 0;i < n; i++) free(p[i]);
    free(p);
}