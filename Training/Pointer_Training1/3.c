/// 인증시험에 계속 나오는 문제!!!

#include <stdio.h>

int main() {
    int ar[50]={0}, N ;
    int *p ;
    scanf("%d", &N);
    for (p = ar; p < ar+N; p++)
        scanf("%d", p);
    int count = 0;
    for (p = ar; p < ar+N; p++) {
        if(*p == 0) {
            break;
        }
            count++;
    }

    printf("%d", count);
    return 0;

}