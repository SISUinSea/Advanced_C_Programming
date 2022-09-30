#include <stdio.h>
int* sel_increase(int *ar, int *len);
int main() {
    int ar[20], len, *startPointer;
    int *p;

    for(p = ar; p < ar + 20 ; p++) {
        scanf("%d", p);
        if(*p == -1) break;
    }

    startPointer = sel_increase(ar, &len);
    for(p = startPointer; p < startPointer + len; p++){
        printf("%d ", *p);
    }
    return 0;
}

int* sel_increase(int *ar, int *len){
    int count, max, *maxIndex, *p, *startIndex;

    max = 0;
    maxIndex = ar;

    for(p = ar+1; *p != -1; p++){
        if(*(p-1) < *p){
            if(count == 1) startIndex = p-1;
            count++;
        }
        else {
            if(max < count) {
                max = count;
                maxIndex = startIndex;
                count=1;
            }
        }
    }
    if(max < count){
        max = count;
        maxIndex = startIndex;
    }

    *len = max;
    return maxIndex;
}

// startIndex 없이도 startIndex를 알아낼 수 있다! len을 이용해서...


// 2번 =  > 한 칸씩 땅겨오기
