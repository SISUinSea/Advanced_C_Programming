#include <stdio.h>

int main() {
    int score101[10], score102[10], tmp;
    int students101, students102, max, min;
    int *p;

    for(p = score101, students101 = 0; p < score101 + 11; p++, students101++){
        scanf("%d", &tmp);
        if(tmp == -1) {
            break;
        }
        *p = tmp;
    }

    min = max = *(score101);

    for(p = score102, students102 = 0; p < score102 + 11; p++, students102++){
        scanf("%d", &tmp);
        if(tmp == -1) {
            break;
        }
        *p = tmp;
    }

    for(p = score101 ; p < score101 + students101; p++){
        if(max < *p) {
            max = *p;
        }
        if(min > *p){
            min = *p;
        }
    }

    for(p = score102 ; p < score102 + students102; p++){
        if(max < *p) {
            max = *p;
        }
        if(min > *p){
            min = *p;
        }
    }

    printf("%d %d\n%d %d", students101, students102, max, min);
    return 0;
}

/**
70 50 50 45 5 15 28 46 76 11 -1
70 50 50 45 5 15 28 46 76 11 -1
*/