#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, i;
    char tmp[100+1];
    scanf("%d", &n);
    getchar();
    char **p = (char **) malloc(n*sizeof(char*));
    if(p == NULL) {
        printf("malloc is null\n");
        return -1;

    }

    for(i = 0; i<n; i++){
        gets(tmp);
        p[i] = (char *) malloc((strlen(tmp)+1) * sizeof(char));
        if(p[i] == NULL) {
            printf("Malloc is null");
            return -1;

        }
        strcpy(p[i], tmp);
    }

    for(i = 0; i<n; i++) puts(p[i]);
    for(i = 0; i<n; i++) free(p[i]);
    free(p[i]);
}