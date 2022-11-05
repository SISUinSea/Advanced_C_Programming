#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // printf("dbg... program is started\n");

    int n;
    scanf("%d", &n);
    getchar();
    // printf("dbg... n is passed\n");

    char *p = NULL;
    p = (char *) malloc(n*sizeof(n));

    int i;
    for(i = 0; i<n; i++) scanf("%c", p+i);
    int catcnt = 0;
    for(i = 0; i<n-2; i++){
        if(strncmp("cat", (p+i), 3) == 0) catcnt++;
    }

    printf("%d\n", catcnt);
    return 0;
}