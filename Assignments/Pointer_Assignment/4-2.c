#include <stdio.h>

int main() {
    int score101[10], score102[10], tmp;
    int students101, students102, max, min;
    int *p, *p1, *p2, *index;

    for(p = score101, students101 = 0; p < score101 + 11; p++, students101++){
        scanf("%d", &tmp);
        if(tmp == -1) {
            break;
        }
        *p = tmp;
    }



    for(p = score102, students102 = 0; p < score102 + 11; p++, students102++){
        scanf("%d", &tmp);
        if(tmp == -1) {
            break;
        }
        *p = tmp;
    }


    for(p = score101; p < score101 + students101; p++){
        max = *p;
        index = p;
        for(p1 = p ; p1 < score101 + students101; p1++){
            if(max < *p1) {
                max = *p1;
                index = p1;
            }
        }

        for(p1 = score102 ; p1 < score102 + students102; p1++){
            if(max < *p1) {
                max = *p1;
                index = p1;
            }
        }
        tmp = *p;
        *p = max;
        *index = tmp;

    }





    for(p = score102; p < score102 + students102 ; p++){
        min = *p;
        index = p;
        for(p2 = p; p2 < score102 + students102 ; p2 ++){
            if(min > *p2) {
                min = *p2;
                index = p2;
            }
        }
        tmp = *p;
        *p = min;
        *index = tmp;
    }

    for(p1 = score101 ; p1 < score101 + students101; p1++)printf("%d ", *p1);
    printf("\n");
    for(p2 = score102 ; p2 < score102 + students102 ; p2++) printf("%d ", *p2);

    return 0;
}

/**
70 50 50 45 5 15 28 46 76 11 -1
70 50 50 45 5 15 28 46 76 11 -1
*/