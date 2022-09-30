#include <stdio.h>
int* MAX(int *ar);
int* MIN(int *ar);
int main() {
// isPrinted : check whether for loop print is executed.
// n : determine loop time
    int n, isPrinted = 0;
// get n variable from user
    scanf("%d", &n);
// pointer
/**
 * minIndex : save min value
 * maxIndex : save max value
 * startIndex : save smaller pointer value between maxIndex and minIndex.
 * endIndex : save bigger pointer value between maxIndex and minIndex.
*/
    int *minIndex, *maxIndex, *startIndex, *endIndex;

// array named ar. it will has 100 elements at most.
    int ar[100];
// pointer p for control array. no [] will be used after this line.
    int *p;

// n times loop
for(int i = 0; i < n; i++){
// set isPrinted value to 0 before starting for loop. 
// it will tell at the end of the for loop that whether printing action is executed.
    isPrinted = 0;

// get array ar information from user. array will be completed right after value '0' is passed.
    for(p = ar; p < ar+100; p++){
        scanf("%d", p);
        if(*p == 0) break;
    }

    // for(p = ar; *p; p++) printf("%d", *p);

// save maxIndex from calling MAX function
    maxIndex = MAX(ar);
// save min index by calling MIN function
    minIndex = MIN(ar);
// the former pointer will be startIndex
    startIndex = maxIndex < minIndex ? maxIndex : minIndex;
// the latter pointer will be endIndex
    endIndex = maxIndex < minIndex ? minIndex : maxIndex;

// printing space value.
// if at least one element is printed, isPrinted value will be 1.
    for(p = startIndex+1; p < endIndex ; p++){
        printf("%d ", *p);
        isPrinted = 1;
    }
    printf("\n");
// if nothing is printed, print 'none'.
    if(!isPrinted) printf("none\n");
}
    return 0;
}

int* MAX(int *ar){
// set initial max variable as array's first element.
// if the initial max variable is not changed, then first element is biggest val in this array.
    int max = *ar;
// index : save max's pointer. initial value will be array's first address.
    int *p, *index = ar;
// check all elements in array
    for(p = ar ; *p ; p++){
// update max value & max address
        if(max < *p) {
            max = *p;
            index = p;
        }
    }
// return max address
    return index;
}

int* MIN(int *ar){
// set initial min variable as array's first element.
// if the initial min variable is not changed, then first element is smallest val in this array.
    int min = *ar;
// index : save min's pointer. initial value will be array's first address.

    int *p, *index = ar;
// check all elements in array
    for(p = ar; *p ; p++){
// update max value & max address
        if(min > *p) {
            min = *p;
            index = p;
        }
        
    }
// return min address
    return index;
}


/**
3
3 7 6 -2 0
1 7 6 13 2 0
2 0

2
13 7 6 6 2 0 
7 3 4 5 6 7 10 4 0
*/