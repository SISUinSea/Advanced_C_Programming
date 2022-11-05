#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    char tmp[100+1], minStr[100+1];
    char **str = (char **) malloc(n*sizeof(char*));
    int  len, min = 102;

    for(int i = 0 ;i < n; i++){
        gets(tmp);
        len = strlen(tmp);
        str[i] = (char *) malloc( (len+1) * sizeof(char) );
        if(str[i] == NULL) return -1;
        strcpy(str[i], tmp);
        if(min > len) {
            min = len;
            strcpy(minStr, str[i]);
        }
    }   

    puts(minStr);


    for(int i = 0; i < n; i++){
        free(str[i]);
    }
    free(str);

    return 0;
    
}

/*
4
Program
Good
This is String
language
*/