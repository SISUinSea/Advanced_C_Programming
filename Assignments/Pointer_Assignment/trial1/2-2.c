#include <stdio.h>
int passengerN(int n);
void rebooking(int *ar);
int changeseat(int *ar);
int main() {
    int n;
    scanf("%d", &n);

    int ar[n+1];
    int *p;
    for(p = ar ; p < ar + n; p ++)scanf("%d", p);
    *(ar+n+1) = -999;
    int isEnough;
    isEnough = passengerN(n);
    if(isEnough == -1) {
        printf("%d\n", isEnough);
        return 0;
    }

    rebooking(ar);
    


    return 0;
}

int passengerN(int n){
    return n < 5 ? -1 : 0;
}

void rebooking(int *ar){
    int *forwardP, *p;

    for(p = ar; *p != -999; p++){
        for(forwardP = p +1; *forwardP != -999; forwardP++){
            if(*forwardP == *p) printf("available seat is : %d\n", changeseat(ar));
        }
    }
}

int changeseat(int *ar){
    int result = -1, *p, flag= 0;
    for(int i = 1; i <= 21; i++){
        flag = 0;
        for(p = ar ; *p != -999 ; p ++){
            if(*p == i) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) continue;
        
        else result = i;
    }
    return result;
}