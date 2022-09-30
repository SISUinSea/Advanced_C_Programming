#include <stdio.h>
int passengerN(int n);
void rebooking(int ar[]);
int changeseat(int *ar);
int main() {
// n for loop time, isEnough will determine the number of reserved passenger is enough.
    int n, isEnough;
// get n from user.
    scanf("%d", &n);
// set array seats length to n +1, because at the end, we will put -999, notifiy that the array is end.
    int seats[n+1];
// pointer p : control the array. no [] will be used after this code line.
    int *p;
// get seats array from user.
    for(p = seats; p < seats + n; p++) scanf("%d", p);
// at the end of the array, there will always be -999, which will notifiy that array is end.
    *(seats+n) = -999;
// if the passenger number is not enought for reservation, then break program.
    isEnough = passengerN(n);
    printf("%d\n",isEnough);
    if(isEnough == -1) return 0;
    // printf("keep going!\n");

// rebooking will be called.
    rebooking(seats);


// after rebooking, the reranged array will be printed.
    for(p = seats; p < seats + n ; p++) printf("%d ", *p);



    return 0;
}

int passengerN(int n){
// isEnough : the return value.
// isEnough => 1 : passenger number are enough to reserve.
// isEnough => 0 : passenger number are not enough.
    int isEnough = 0;
    if(n < 5) isEnough = -1;

    return isEnough;
}

void rebooking(int ar[]){
// pointer p for regular loop controller, forwardP will be used to test array's latter elements.
    int *p, *forwardP;

// loop will be executed until the -999, array-end-notifier is sensed.
    for(p = ar; *p != -999; p++){
// 자신보다 앞선 배열 요소들 중 자신과 같은 아이가 있다면 changeseat 함수를 호출. forwardP가 가리키는 곳에 값을 저장.
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
// seatsData : seatsData will collect data the number of reversed request for each seat.
// i        : to test array. give index number
// result   :  save and return empty seat number
    int seatsData[21+1] = {0,}, i, result = -1;
// pointer p for control array, pointer seatsDataP for control seatsData array.
    int *p, *seatsDataP;
// forming seatsData array.
    for(p = ar; (*p) != -999 ; p++) *(seatsData + (*p))+= 1;
    // for(p = seatsData, i = 0; p < seatsData + 22; p++,i++) printf("%d: %d\n",i,*p);
// recommend empty seats.
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
