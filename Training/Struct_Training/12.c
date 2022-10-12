/*
AKim 80 80 80
BKim 90 90 90
CKim 81 81 81
ALee 82 82 82
BLee 83 83 83
CLee 84 84 84
APark 85 85 85
BPark 86 86 86
CPark 87 87 87
DPark 88 88 88

jrhygc 38 61 35
mnvrsug 18 5 33
lm 16 80 65
hxwpljl 68 93 29
w 73 55 99
oj 25 60 54
xpyvz 87 23 94
xut 23 31 87
ss 90 5 65
ceyl 47 88 2
*/
#include <stdio.h>

struct student {
    char name[9+1];
    int t1, t2, t3;
    double avg;
};

void read_data(struct student students[]);
void cal_avg(struct student students[]);
void sort(struct student students[]);
void print_score(struct student students[]);
int main (){
    struct student students[10];
    read_data(students);
    // for(int i = 0; i< 10; i++) printf("debugging : %s %d %d %d\n", (students+i)->name, (students+i)->t1, (students+i)->t2, (students+i)->t3);
    // int i = 0;
    // printf("debugging : %s %d %d %d\n", (students+i)->name, (students+i)->t1, (students+i)->t2, (students+i)->t3);
    cal_avg(students);
    // for(int i = 0; i<10; i++) printf("debugging 2 : %s %.2lf\n", (students+i)->name, (students+i)->avg);


    sort(students);
    // for(int i = 0; i<10; i++) printf("debugging 3 : %s %.2lf\n", (students+i)->name, (students+i)->avg);
    print_score(students);


    return 0;
}   

void read_data(struct student students[]){
    for(int i =0; i<10;i++){
        scanf("%s %d %d %d", (students+i)->name, &((students+i)->t1), &((students+i)->t2), &((students+i)->t3));
        getchar();
    }

}
void cal_avg(struct student students[]){
    for(int i = 0; i< 10; i++){
        (students+i)->avg = ( (students+i)->t1+(students+i)->t2+(students+i)->t3 )/3.0;
    }
}
void sort(struct student students[]){
    // int i,j, maxIndex;
    // struct student tmp, maxStudent;
    // double max = 0;

    // for(i=0; i<10; i++){
    //     max = (students+i) -> avg;
    //     maxStudent = *(students+i);
    //     for(j=i+1; j<10;j++){
    //         if(max < (students+j)->avg){
    //             max = (students+j) -> avg;
    //             maxStudent = *(students+j);
    //             maxIndex = j;
    //         }
    //         tmp = *(students+i);
    //         *(students+i) = *(students+maxIndex);
    //         *(students+maxIndex) = tmp;
    //     }
    // }
    int i,j;
    struct student tmp;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if( (students+j)->avg < (students+j+1)->avg ){
                tmp  = *(students+j);
                *(students+j) = *(students+j+1);
                *(students+j+1) = tmp;
            }
        }
    }
}


void print_score(struct student students[]){
    printf("%s %.2lf\n", (students+0)->name, (students+0)->avg);
    printf("%s %.2lf\n", (students+9)->name, (students+9)->avg);
    printf("%s %.2lf\n", (students+7)->name, (students+7)->avg);
    printf("%s %.2lf\n", (students+8)->name, (students+8)->avg);
    printf("%s %.2lf\n", (students+9)->name, (students+9)->avg);
    
}
