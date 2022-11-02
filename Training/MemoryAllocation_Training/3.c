#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar();

    char *p = NULL;
    p = (char *) malloc(n*sizeof(char));

    int i;
    for(i=0;i<n;i++) scanf("%c", p+i);
    getchar();

    char s1, s2;
    int s1cnt = 0, s2cnt = 0;
    scanf("%c %c", &s1, &s2);
    for(i = 0; i<n; i++) {
        if(*(p+i) ==s1)  s1cnt++;
        if(*(p+i) ==s2)  s2cnt++;
    }

    printf("%d %d\n", s1cnt, s2cnt);
    return 0;
}