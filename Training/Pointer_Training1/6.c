#include <stdio.h>

int main(){
    char ch[10];
    char *p, *p2;

    for(p = ch; p < ch + 10; p++) scanf("%c", p);

    int count = 0, maxCount = 0;
    char *max = NULL;

    for(p = ch; p < ch + 10; p++) 
    {
        count = 0;
        for(p2 = ch; p2 < ch + 10; p2++) if(*p == *p2) count++;

        if(maxCount < count) {
            maxCount = count;
            max = p;
        }
        
    }

    printf("%c %d\n", *max, maxCount);
    return 0;
}