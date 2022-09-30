#include <stdio.h>

int main() {
    int length = 0, wordLen = 0;
    char final, string[1001];
    char *p, *startIndex, *endIndex, *p2;

    for(p = string, length = 0; ;p++){
        scanf("%c", p);
        length++;
        if(*p == '?' || *p == '!' || *p == '.') break;
    }

    // for(p = string; p < string + length; p++)printf("%c", *p);
    final = *(string + length-1);
    // printf("%c\n", final);

    // for(p = (string + length-1)-1; p >= string ; p--) printf("%c", *p);
    
    for(p = (string + length-1)-1; p >= string ; p--) {
                // printf("FIRST FOR LOOP START\n");
        if(*p != ' '){
                // printf("IF STATEMENT EXECUTED\n");
            wordLen ++;
            if(wordLen == 1) endIndex = p;
            startIndex = p;
        }else {
                // printf("ELSE STATEMENT EXECUTED\n");
            // print 
            for(p2 = startIndex; p2 <= endIndex; p2++) printf("%c", *p2);
            if(p != string) printf(" ");
            // change wordLen  = 0;
            wordLen = 0;
        }
    }
    startIndex = p;
    for(p2 = startIndex; p2 <= endIndex; p2++) printf("%c", *p2);
    printf("%c\n", final);
    
    return 0;

}

/**
you can cage a swallow can't you?
*/
