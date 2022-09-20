#include <stdio.h>
void ABC(int *s, int k);
int main() {
    int x[10],i;
    int *p;

    for(p = x; p < x+10; p++)scanf("%d", p);

    for(p = x, i = 10; p < x+10-1; p++, i--){
        ABC(p,i);
    }
    return 0;
}

void ABC(int *s, int k){

}
