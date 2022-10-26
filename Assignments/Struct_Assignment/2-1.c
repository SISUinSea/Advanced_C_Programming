/*
5
Kim 100 90 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
*/

#include <stdio.h>
struct student {
    char name[20+1];
    int kor, eng, math;
};
struct average{
    double kor, eng, math;
};

struct average calculate_avg(struct student *st, int n);
int main() {
    int n,i;
    int korLTA, engLTA, mathLTA;
    engLTA = korLTA = mathLTA = 0;
    scanf("%d", &n);
    struct student students[n];
    for(i = 0; i<n; i++) 
        scanf("%s %d %d %d", 
            students[i].name, 
            &(students[i].kor), 
            &(students[i].eng), 
            &(students[i].math));
    struct average avg;
    avg = calculate_avg(students, n);
    printf("%.1lf %.1lf %.1lf\n", avg.kor, avg.eng, avg.math);

    for(i=0; i<n;i++){
        if(avg.kor > students[i].kor) korLTA++;
        if(avg.math > students[i].math) mathLTA++;
        if(avg.eng > students[i].eng) engLTA++;
    }

    printf("%d %d %d\n", korLTA, engLTA, mathLTA);
    return 0;
}

struct average calculate_avg(struct student *st, int n){
    struct average avg;
    double myValue;
    int i;
    for(i=0; i<n; i++){
        avg.eng += (st+i)->eng;
    }
    avg.eng /= (double) n;
    for(i=0; i<n; i++){
        avg.kor += (st+i)->kor;
    }
    avg.kor /= (double) n;
    for(i=0; i<n; i++){
        avg.math += (st+i)->math;
    }
    avg.math /= (double) n;

    return avg;
}
