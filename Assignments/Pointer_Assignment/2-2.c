#include <stdio.h>

int passengerN(int n);
void rebooking(int ar[]);
int changeseat(int *ar);
int main() {
    int n, isEnough;
    scanf("%d", &n);
    int seats[n+1], seatsData[21+1] = {0,};
    int *p;

    for(p = seats; p < seats + n; p++) scanf("%d", p);
    *(seats+n) = -999;

    isEnough = passengerN(n);
    printf("%d\n",isEnough);
    if(isEnough == -1) return 0;
    // printf("keep going!\n");


    rebooking(seats);

    for(p = seats; p < seats + n ; p++) printf("%d ", *p);



    return 0;
}

int passengerN(int n){
    int isEnough = 0;
    if(n < 5) isEnough = -1;

    return isEnough;
}

void rebooking(int ar[]){
    int *p, *forwardP;


    for(p = ar; *p != -999; p++){
        for(forwardP = p+1; (*forwardP) != -999; forwardP++){
            if(*forwardP == *p){
                // printf("call changeseat method. %d\n",*forwardP);
                *forwardP = changeseat(ar);
            }
        }
    }
}

/**
7
1 2 3 3 4 5 6

6
8 3 3 3 1 4
*/

int changeseat(int *ar){
    int seatsData[21+1] = {0,}, i, result = -1;
    int *p, *seatsDataP;
    for(p = ar; (*p) != -999 ; p++) *(seatsData + (*p))+= 1;
    // for(p = seatsData, i = 0; p < seatsData + 22; p++,i++) printf("%d: %d\n",i,*p);

    for(seatsDataP = seatsData+1; seatsDataP <= seatsData + 21;seatsDataP++){
        if((*seatsDataP) == 0){
            (*seatsDataP)+=1;
            result = (int)(seatsDataP-seatsData);
            // printf("current index: %d, current val: %d\n", result, *seatsDataP);
            break;
        }
    }
    return result;
}
