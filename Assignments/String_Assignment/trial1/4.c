/*
ClanguageIsInteres  ting

3
2  9
ClanguageIsInteres  ting
CCC  CCCC
LanguageC
*/
#include <stdio.h>
int s_check(char *s, char *e);
int main() {
    int m;
    int k1, k2;
    int count;
    char str[200+1];
    scanf("%d", &m);
    scanf("%d %d",&k1, &k2);
    getchar();
    for(int i = 0; i<m; i++){
        gets(str);
        // puts(str);
        count = s_check(str+k1, str+k2);
        if(count)
            printf("%d\n", count);
    }
    
    return 0;
}

int s_check(char *s, char *e){
    char *p;
    int count = 0;
    for(p = s; p <= e && *p; p++){
        if(*p >= 'a' && *p <= 'z'){
            count ++;
        }
    }

    return count ;
}\
