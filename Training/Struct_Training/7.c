/*
78 65 23 43 82 95 31 15 8 54
*/

#include <stdio.h>
struct data {
    int score;
    int rank;
};
int main() {
    struct data data[10];
    int i,j, tmp[10], count;
    for(i=0; i<10; i++) scanf("%d", &tmp[i]);

    for(i=0; i<10; i++){
        count = 1;
        data[i].score = tmp[i];

        for(j=0; j<10; j++){
            if(tmp[i] < tmp[j]) {
                count++;
            }
        }
        data[i].rank = count;
    }
    // for(i=0; i<10; i++) printf("%d %d\n", data[i].rank, data[i].score);
    for(i=0; i<10; i++) {
        if(data[i].rank == 3){
            printf("%d ", data[i].score);
            break;
        }
    }
    for(i=0; i<10; i++){
        if(data[i].rank == 7) {
            printf("%d\n",data[i].score);
            break;
        }
    }
    return 0;
}