#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,i;
    scanf("%d", &n); getchar();

    char tmp[100+1];

    char ** str = (char **) malloc(n*sizeof(char*));
    if(str== NULL){
        return -1;
    }

    int len;
    for(i=0; i<n; i++){
        gets(tmp);
        len = strlen(tmp);
        str[i] = (char *) malloc((len+1)*sizeof(char));
            if(str[i] == NULL) return -1;
        strcpy(str[i],tmp);
    }

    int j;
    char *tmpStr;
    for(i = 0; i<n; i++) {
        for(j = 1; j < n; j++){
            if( strlen(str[j-1]) < strlen(str[j]) ){
                // strcpy(tmp, str[j]);
                // strcpy(str[j], str[j-1]);
                // strcpy(str[j-1], tmp);
                tmpStr = str[j];
                str[j] = str[j-1];
                str[j-1] = tmpStr;
            }
        }
    }


    for(i = 0; i<n; i++) puts(str[i]);
}