#include <stdio.h>
#include <string.h>
int check(char *ar);
int main() {
    char ar[30+1];
    gets(ar);
    printf("%d %d\n",(int) strlen(ar), check(ar));


    return 0;
}

int check(char *ar){
    int length = strlen(ar), result = 1;
    char *p, *endP;

    for(p = ar, endP = ar + length-1; p < ar + (length/2) && p!=endP;p++, endP--){
        if(*p != *endP){
            result = 0;
            break;
        }
    }
    return result;
}
