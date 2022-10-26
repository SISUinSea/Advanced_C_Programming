/*
7 3
Aaaaa 1995-10-07 75 85 
Bbbbb 1991-11-15 90 64 
Ccccc 1994-12-08 94 82 
Ddddd 1993-07-17 78 70 
Eeeee 1995-10-07 65 85 
Fffff 1991-11-05 90 64 
Ggggg 1990-08-21 90 64
*/

#include <stdio.h>
struct HR {
    char name[10+1];
    int paper, meeting;
    int year, month, day;
    double total;
};

void swap(struct HR *p, struct HR *q);

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    struct HR data[n];
    
    int i;
    for(i = 0; i<n; i++){
        scanf("%s %d-%d-%d %d %d", data[i].name, &data[i].year, &data[i].month, &data[i].day, &data[i].paper, &data[i].meeting);
    }

    for(i = 0; i<n; i++){
        data[i].total = data[i].paper*0.8 + data[i].meeting*0.2;
    }

    int j;
    for(i = 0; i<n; i++){
        for(j = 1; j<n; j++){
            if(
                data[j-1].total < data[j].total 
                ||
                data[j-1].total == data[j].total && data[j-1].paper < data[j].paper
                ||
                data[j-1].total == data[j].total && data[j-1].paper == data[j].paper && data[j-1].meeting == data[j].meeting && 
                data[j-1].year < data[j].year 
                ||
                data[j-1].total == data[j].total && data[j-1].paper == data[j].paper && data[j-1].meeting == data[j].meeting && 
                data[j-1].year == data[j].year && data[j-1].month < data[j].month 
                ||
                data[j-1].total == data[j].total && data[j-1].paper == data[j].paper && data[j-1].meeting == data[j].meeting && 
                data[j-1].year == data[j].year && data[j-1].month == data[j].month && data[j-1].day < data[j].day 
            ){
            swap(data+j-1, data+j);
        }
        }
    }

    for(int i = 0; i< m; i++){
        printf("%s %.1lf\n", data[i].name, data[i].total);
    }
}

void swap(struct HR *p, struct HR *q){
    struct HR tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}