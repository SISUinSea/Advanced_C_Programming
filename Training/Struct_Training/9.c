#include <stdio.h>
struct result{
    int high, low, gap, stdgap;
    char passOrNot;
};
void passorfail(struct result *r);
int main() {
    struct result r;
    scanf("%d %d %d", &r.high, &r.low, &r.stdgap);
    passorfail(&r);
    printf("%d %c\n",r.gap, r.passOrNot);
    return 0;
}
void passorfail(struct result *r){
    (*r).gap = (*r).high > (*r).low ? (*r).high-(*r).low : (*r).low-(*r).high;
    if( (*r).gap < (*r).stdgap ) (*r).passOrNot = 'P';
    else (*r).passOrNot = 'F';
}
