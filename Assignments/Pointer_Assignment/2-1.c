#include <stdio.h>

int main() {
    // n : decide array's length.
    int n;
    scanf("%d", &n);


    // seats: array's name. 
    // count: for counting the amount of seats which is double-counted.
    int seats[n], count;
    // for(int i = 0; i < 21 ; i++) printf("%d ", seats[i]);

    // state p, p2 as pointer to control array 'seats'.
    int *p, *p2;

    // variable isSame will be used as Boolean. 0 means false, 1 means true.
    int isSame = 0;

    // seats array get its data.
    for(p = seats; p < seats + n; p++) scanf("%d", p);


    // @First BreakPoint: if reserved seats is smaller than 5, print -1 and kill program.
    if(n < 5){
        printf("-1\n");
        return 0;
    }


    // finding how many seats is being double-checked.
    for(p = seats; p < seats + n; p++){
        // To print one output per one double-checked seat, 
        // test if previous element is same with current one.
        for(p2 = p-1; p2 > seats; p2--){
            if(p2 < seats) continue;
            // if same, go to next element and keep testing.
            else if(*p2 == *p) break;
        }
        if(*p2 == *p) continue;
        // p2 value is kept as p2 is stated outside of this for loop.

        // Here we will search backward and find if any element is same with current one.
        // if so, make count variable +1.
        // searching algorithm will not include myself, so set count variable as 1.
        count = 1;  
        for(p2 = p+1; p2 < seats + n; p2 ++){
        // if same, make count variable +1.
            if(*p2 == *p) {
                count++;
                // and tell to program that in this array, 
                // there are some double-checked seats.
                isSame = 1;
            }
        }
    // only print if the count variable is bigger than 1.
    // which means current seat is double-checked.
        if(count > 1) printf("%d %d\n", *p, count);
    }

    // if no seat is double-checked, print 0.
    if(!isSame) printf("0\n");
    return 0;
}