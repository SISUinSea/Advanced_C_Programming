/*
lee1 2017102656 A
lee2 2018111823 A
kwon 2018111888 A
park 2018059961 A
choi 2018010101 B
park
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student {
    char name[9+1];
    char id[10+1];
    char score;
};
int main(){
    struct student students[5]; // 입력받을 student struct 배열을 선언
    int i, flag = 0;        // for loop control을 위한 i, 같은 학번이 있는가의 정보를 저장하는 flag
    char searchWord[9+1], searchedYear[4+1], searchedScore; // 입력받을 이름, 입력받은 이름의 학번, 입력받은 이름의 학점을 저장할 배열들
    for(i = 0; i<5; i++){// 정보를 입력받음
        scanf("%s %s %c", students[i].name, students[i].id, &(students[i].score));
        getchar();// %c는 개행문자\n를 삼키기 않는다. 24번째 줄 없이는 i+1번째의 첫 %s에 아무 것도 전달되지 않게 된다.
    }
    gets(searchWord);
    
    for(i=0; i<5;i++){ // students 중에서 찾고자 하는 이름이 있는지 순차 검색
        if(strcmp(searchWord, students[i].name)==0){// 만약 있다면
            strncpy(searchedYear, students[i].id, 4);// 학번, 학점을 저장한 다음 for loop를 종료
            searchedScore = students[i].score;
            break;
        }
    }

    for(i=0; i<5; i++){ // students 중에서 searched된 학번, 학점에 해당하는 학생이 있는지 순차 검색
        if(strncmp(searchedYear, students[i].id, 4) == 0 && // 만약 있다면
            searchedScore == students[i].score
            ){
            if(strcmp(searchWord, students[i].name) == 0) continue;//(본인은 제외)
            printf("%s ", students[i].name);// 해당 학생의 이름을 출력
            flag = 1; // 적어도 조건을 만족하는 학생이 있다면 flag를 1로 수정
        }
    }

    if(flag == 0) printf("0");// 위 조건을 만족하는 학생이 아무도 없을 때 0를 출력
    
    printf("\n");

    int yearToInt = atoi(searchedYear);// 문자 타입의 변수를 atoi()함수를 사용해 정수로 변환
    printf("%d %d\n", yearToInt, yearToInt%131);// 정수를 이용해 결괏값 출력
    return 0;
}