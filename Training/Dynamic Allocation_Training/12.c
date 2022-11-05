#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    char tmp[100+1];
    int i,j, len;

    scanf("%d", &n);getchar();
    char **p = (char **) malloc(n*sizeof(char*));
    if(p==NULL) return-1;
    

    for(i=0;i<n;i++){
        gets(tmp);
        len = strlen(tmp);
        p[i]= (char*) malloc((len+1)*sizeof(char));
        strcpy(p[i], tmp);
    }


    char *tmpstr;
    for(i = 0; i<n; i++){
        for(j = 1; j<n;j++) {
            if(strcmp(p[j-1], p[j]) > 0 ){
                tmpstr = p[j];
                p[j] = p[j-1];
                p[j-1] = tmpstr;
            }
        }
    }
    for(i=0;i<n;i++) puts(p[i]);

}