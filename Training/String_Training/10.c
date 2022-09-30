#include <stdio.h>
#include <string.h>

int main() {
    char str[101], arr[101];
    int cnt, min = 0;

    int i;
    int n;

    scanf("%d", &n);
    getchar();

    gets(arr);
    min = strlen(arr);
    for(i = 1; i < n; i++){
        gets(str);
        cnt = strlen(str);
        if(cnt <= min){
            min = cnt;
            strcpy(arr, str);
        }
    }
    printf("%s", arr);
    return 0;
}

/*
4
Program
good
this is string
language
*/