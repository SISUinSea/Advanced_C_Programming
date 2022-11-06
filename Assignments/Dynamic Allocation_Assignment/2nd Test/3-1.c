#include <stdio.h>

typedef struct person {
    char name[10+1];
    int test1, test2;
    double total;
} P;

void swap(P *p, P *q);

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    int i;
    P data[n];//이거 vs에서는 안 되던데,,, 나중에 체크 해보자.
    for(i = 0; i<n; i++){
        scanf("%s %d %d", (data+i)->name, &(data+i)->test1, &(data+i)->test2);
        // getchar();
        (data+i)->total = (data+i)->test1 * 0.8 + (data+i)->test2 * 0.2;
    }

     int j;
    for(i = 0; i<n; i++) {
        for(j = 1; j<n; j++) {
            if((data+j-1)->total < (data+j)->total) 
                swap((data+j-1), (data+j));
        }
    }

    for(i = 0; i<m; i++) printf("%s %.1lf\n", (data+i)->name, (data+i)->total);
}

void swap(P *p, P *q){
    P tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}
