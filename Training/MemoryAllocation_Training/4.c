/*
2
kim 100 82 34
sisu 180 500 100
*/

#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[7+1];
    int kor, eng, math;
    double avg;
};
int main(){
    int n;
    scanf("%d", &n);
    getchar();

    // printf("dbg... i receive n value!\n");

    struct student *p = NULL;
    p = (struct student *) malloc(n*sizeof(struct student));

    int i;
    for(i = 0; i<n; i++) {
        // printf("dbg... scanf for loop\n");
        scanf("%s %d %d %d", (p+i)->name, &(p+i)->kor, &(p+i)->eng, &(p+i)->math);
        getchar();
    }
     for(i = 0; i<n; i++) 
     {
        (p+i)->avg = ((p+i)->kor + (p+i)->eng + (p+i)->math) / 3.0;
     }

    for(i = 0; i<n; i++) {
        printf("%s %.1lf ", (p+i)->name, (p+i)->avg);
        if( (p+i)->kor >= 90 
            || (p+i)->eng >= 90 
            || (p+i)->math >= 90)
            printf(" GREAT");
        if( (p+i)->kor < 70 
            || (p+i)->eng < 70 
            || (p+i)->math < 70)
            printf(" BAD");
        printf("\n");
    }
    return 0;
}