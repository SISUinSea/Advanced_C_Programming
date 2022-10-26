/*
marriott 4 4.7 12.5 Y
ibis 2 3.5 5.6 N
novotel 3 3.0 2.7 N
renaissance 3 3.5 4.8 N
hyatt 5 3.5 7.4 Y
bestwestern 2 2.5 3.8 Y
0
*/

#include <stdio.h>
#include <string.h>
struct hotel_info {
    char name[30+1];
    int grade;
    double rate;
    double distance;
    char breakfast; // 'Y' || 'N'
};

int in_hotel_info(struct hotel_info p[]);

int main() {
    struct hotel_info hotels;
    return 0;
}

int in_hotel_info(struct hotel_info p[]){

    
    return 1;
}
