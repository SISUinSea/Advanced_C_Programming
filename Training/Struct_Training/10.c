#include <stdio.h>
struct datetime {
    int year, month, day;
};
struct datetime* select_min(struct datetime *d1, struct datetime *d2);
int main() {
    struct datetime d1, d2, *dResult;
    scanf("%d/%d/%d", &d1.year, &d1.month, &d1.day);
    scanf("%d/%d/%d", &d2.year, &d2.month, &d2.day);
    dResult = select_min(&d1, &d2);
    printf("%d/%d/%d\n",(*dResult).year, (*dResult).month, (*dResult).day);
    return 0;
}

struct datetime* select_min(struct datetime *d1, struct datetime *d2){
    if( (*d1).year< (*d2).year) return d1;
    else if( (*d1).year > (*d2).year ) return d2;
    else {
        if( (*d1).month < (*d2).month )return d1;
        else if( (*d1).month > (*d2).month ) return d2;
        else {
            if( (*d1).day< (*d2).day ) return d1;
            else if( (*d1).day> (*d2).day ) return d2;
            else return d1;// whatever
        }
    }
}
