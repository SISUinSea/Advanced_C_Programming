#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int*p;

    for(p = arr; p < arr +n ; p++)scanf("%d", p);
    // for(p = arr; p < arr +n ; p++)printf("%d", *p);
    int *previousP, *forwardP;
    int cnt;

    for(p = arr; p < arr + n; p ++){
        cnt = 1;
        for(previousP = p -1; previousP  >= arr; previousP--){
            if(*previousP == *p) break;
        }
            if(*previousP == *p) continue;
        for(forwardP = p+1; forwardP < arr + n; forwardP ++){
            if(*forwardP == *p) cnt++;
        }

        if(cnt != 1) printf("%d %d\n", *p, cnt);

    }
}

/*
8
7 2 5 5 20 5 8 7
*/
