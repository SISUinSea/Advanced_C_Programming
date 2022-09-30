#include <stdio.h>

int main() {
// set two arrays named score101 and score102. each of them will save scroes from room101 and room 102.
// tmp for swapping data
    int score101[10], score102[10], tmp;
// set two variable for saving class's students.
// max and min : saving max value and min value.
    int students101, students102, max, min;
// pointer p, p1, p2 is used to controll loop. index will save speacial variable's address.
    int *p, *p1, *p2, *index;
// first thing first, we will get score101 data and students from room 101.
    for(p = score101, students101 = 0; p < score101 + 11; p++, students101++){
        scanf("%d", &tmp);
        if(tmp == -1) {
            break;
        }
        *p = tmp;
    }
// last input value is always be -1.

// then we will get score101 data and students from room 102.
    for(p = score102, students102 = 0; p < score102 + 11; p++, students102++){
        scanf("%d", &tmp);
        if(tmp == -1) {
            break;
        }
        *p = tmp;
    }
// last input value is always be -1.

// sorting max scores to score101 array.
    for(p = score101; p < score101 + students101; p++){
// max's initial data will be score101's first element.
        max = *p;
// index's initial data will be score101's first element's address.
        index = p;
// first looping through score101 array, find which score is the highest and save it and its address to max and index.
        for(p1 = p ; p1 < score101 + students101; p1++){
            if(max < *p1) {
                max = *p1;
                index = p1;
            }
        }
// first looping through score102 array, find which score is the highest and save it and its address to max and index.
        for(p1 = score102 ; p1 < score102 + students102; p1++){
            if(max < *p1) {
                max = *p1;
                index = p1;
            }
        }
// then the max variable contains max score in this test.
// swap it.
        tmp = *p;
        *p = max;
        *index = tmp;

    }


// max sorting is done.
// now its time for min sorting.

// at this point, score101 is contain the higher scores in this test.
// so the score102 array is automatically contains the lower scores.
// only we have to do is sorting.
    for(p = score102; p < score102 + students102 ; p++){
// min initial value is its first elelment in this loop.
        min = *p;
// index initial value is its first element' address in this loop.
        index = p;
// find which score is lowest score and save it and its address to min and index.
        for(p2 = p; p2 < score102 + students102 ; p2 ++){
            if(min > *p2) {
                min = *p2;
                index = p2;
            }
        }
// swap it.
        tmp = *p;
        *p = min;
        *index = tmp;
    }
// print its result.
    for(p1 = score101 ; p1 < score101 + students101; p1++)printf("%d ", *p1);
    printf("\n");
    for(p2 = score102 ; p2 < score102 + students102 ; p2++) printf("%d ", *p2);

    return 0;
}

/**
70 50 50 45 5 15 28 46 76 11 -1
70 50 50 45 5 15 28 46 76 11 -1
*/