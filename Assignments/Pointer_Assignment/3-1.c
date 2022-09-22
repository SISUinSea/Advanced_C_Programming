#include <stdio.h>
int is_atoz(char c);
void PRT(int n, char *s);
int main() {
    char ch[100];
    char *p, *firstIndex, *maxFirstIndex;

    int count, maxCount;
    count = maxCount = 0;

    for (p = ch; ;p++){
        scanf("%c", p);
        if(*p == '#') break;
    }

    for(p = ch; ; p++){
        if(*p == '#') break;


        if(is_atoz(*p)) {
            printf("%c", *p);
            if(count == 0) firstIndex = p;
            count ++;
        }
        else {
            if(is_atoz(*(p-1))){
                printf("\n");
                if(maxCount < count) {
                    maxCount = count;
                    maxFirstIndex = firstIndex;
                }
                count = 0;
            }
            // else{

            // }
        }
    }
    // printf("!!!right after exiting for loop, the *p is ...%c.!!!\n", *p);
    if(maxCount < count) {
        maxCount = count;
        maxFirstIndex = firstIndex;
    }
    if(is_atoz(*(p-1))) printf("\n");
    printf("%d %c\n",maxCount, *maxFirstIndex);
    PRT(maxCount, maxFirstIndex);

    return 0;
}

/**
banana25apple#
*/

int is_atoz(char c){
    int result = 0;
    if(c >= 'a' && c <='z') result = 1;
    // if return value is 0, it means the character is not a small alphabet.
    // if return value is 1, it means the character is  a small alphabet.
    return result;
}


void PRT(int n, char *s){
    char *p;

    for(p = s; p < s + n; p ++) printf("%c", *p);
    printf("\n");
}
