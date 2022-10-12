#include <stdio.h>
#include <string.h>

int main() {
    char str[200+1];
    char arr[20][200], tmp[200];
    int ai, aj,i;
    gets(str);

    for(i = 0, ai = 0, aj = 0; str[i]; i++){
        if(str[i]!=' '){
            arr[ai][aj++] = str[i];
            printf("%c", str[i]);
        }else {
            arr[ai++][aj] = '\0';
            aj = 0;   
            printf("\n");
        }
    }printf("\n");
    arr[ai++][aj] = '\0';
    for(int j = 1; j < ai ; j++){
        for(i = 1; i < ai; i++){
            if(strcmp(arr[i-1],arr[i]) > 0){
                strcpy(tmp, arr[i]);
                strcpy(arr[i], arr[i-1]);
                strcpy(arr[i-1], tmp);
            }
        }
    }
    for(int i = 0; i < ai; i++) printf("%s ", arr[i]);
    return 0;
}