#include <stdio.h>
#include <stdlib.h>
char alphabet(char ch);
int main(){
    int column, row;
    scanf("%d %d", &column, &row);

    char **p = NULL;
    p = (char **) malloc(row*sizeof(char*));

    int i;
    for(i = 0; i<row; i++) 
        *(p+i) = (char *) malloc(column*sizeof(char));
    
    int j;
    char c = 'a';
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            *(*(p+i)+j) = c;
            c = alphabet(c);
        }
    }

    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            printf("%c ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}

char alphabet(char ch){
    char result;
    if(ch >= 'a' && ch < 'z') result = ch+1;
    else if(ch == 'z') result = 'A';
    else if(ch >='A' && ch < 'Z') result = ch+1;
    else if(ch == 'Z') result = 'a';
    return result;
}
