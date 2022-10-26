/*
5
Kim 100 85 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
Song 100 90 97
Lee 92 82 93
Park 80 84 72
Choi 97 80 90
Chung 100 94 93
*/

#include <stdio.h>
struct student {
    char name[20+1];
    int kor, eng, math;
    double avg;
};


void read_data(struct student students[], int n);
void sort_score(struct student students[], int n);
struct student * select_out(struct student st1[], struct student st2[], int n);
int main() {
    int n,i; // 학생수를 결정하는 변수 n, for loop를 control하기 위한 변수 i 선언
    scanf("%d", &n);
    struct student st1[n], st2[n]; // n을 입력받아 student struct 배열  2개를 생성


    read_data(st1,n);// read_data() 함수를 이용해 각 배열의 값을 입력받아 저장
    read_data(st2,n);

    // printf("-------------- debugging start 1---------\n");
    // for(i=0;i<n;i++) printf("%s %.2lf\n", st1[i].name, st1[i].avg);
    // for(i=0;i<n;i++) printf("%s %.2lf\n", st2[i].name, st2[i].avg);

    sort_score(st1,n);// sort_score() 함수를 이용해 각 배열을 정렬
    sort_score(st2,n);
    // printf("-------------- debugging start 2---------\n");
    // for(i=0;i<n;i++) printf("%s %.2lf\n", st1[i].name, st1[i].avg);
    // for(i=0;i<n;i++) printf("%s %.2lf\n", st2[i].name, st2[i].avg);

    struct student *result = select_out(st1, st2, n); // select_out() 함수를 이용해 나온 결과 student 포인터를 result에 저장.
    for(i=0;i<n;i++)printf("%s %d %d %d %.1lf\n", (result+i)->name, (result+i)->kor, (result+i)->eng, (result+i)->math, (result+i)->avg);// 출력
    return 0;
}


void read_data(struct student students[], int n){
    int i;// for loop를 control하기 위한 i 변수 선언
    for(i=0; i<n; i++) // 배열의 크기만큼 반복
        scanf("%s %d %d %d", // 구조체 정보를 입력받아 저장
            students[i].name, &(students[i].kor), &(students[i].eng), &(students[i].math));
    for(i=0;i<n;i++){
        students[i].avg = (students[i].kor + students[i].eng + students[i].math)/3.0;
    }
}

void sort_score(struct student students[], int n){
    int i,j;// nested for loop controlling을 위한 변수 i,j선언
    struct student tmp;// swap을 위한 student 변수 tmp 선언
    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            if((students+j-1)->avg < (students+j)->avg          // 평균값이 작은 학생이 앞에 있
                ||                                              // 거나
                (students+j-1)->avg == (students+j)->avg &&     // 평균 값은 같은데
                (students+j-1)->kor < (students+j)->kor         // 국어 점수가 작은 학생이 앞에 있
                ||                                              // 거나
                (students+j-1)->avg == (students+j)->avg &&     // 평균이 같고
                (students+j-1)->kor == (students+j)->kor &&     // 국어도 같은데
                (students+j-1)->eng < (students+j)->eng         // 영어 점수가 작은 학생이 앞에 있다면
            ) {// swap을 실행
                tmp = *(students+j-1);
                *(students+j-1) = *(students+j);
                *(students+j) = tmp;
            } 
        }
    }
}

struct student *select_out(struct student st1[], struct student st2[], int n){
    struct student *resultSt; // 토해낼 student 변수를 resultSt로 선언

    if( (st1+((n-1)/2))->avg <  (st2+((n-1)/2))->avg ) resultSt = st2; // 중간값이 작은 애를 resultSt에 저장
    else resultSt = st1;

    return resultSt;// 반환
}
