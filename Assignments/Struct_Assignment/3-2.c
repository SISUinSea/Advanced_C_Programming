/*
marriott 4 4.7 12.5 Y
ibis 2 3.5 5.6 N
novotel 3 3.0 2.7 N
renaissance 3 3.5 4.8 N
hyatt 5 3.5 7.4 Y
bestwestern 2 2.5 3.8 Y
0
3 7.5
*/

#include <stdio.h>
#include <string.h>

struct hotel_info {
    char name[30+1];
    int grade;
    double rate, distance;
    char breakfast;
};

int in_hotel_info(struct hotel_info *p);
void out_hotel_info(struct hotel_info *p, int n, int g, double d);

int main() {
    // printf("debugging 0: main function starts\n");
    int g; double d;// g for grade, d for distance
    struct hotel_info hotels[100];// 입력받을 hotel_info struct 배열 저장을 위한 변수 선언
    int len, i;// hotels 배열의 크기를 저장할 len, for loop controlling을 위한 변수 i선언

    len = in_hotel_info(hotels);// len에 in_hotel_info() 함수의 return value를 저장
    scanf("%d %lf", &g, &d);// g, d 값을 입력받아 각 배열에 저장하기
    // printf("main() => debugging: len is ... %d\n", len);
    // printf("main()=> debugging : d and g are ...%d %.1lf\n", g, d);
    out_hotel_info(hotels, len, g, d);// out_hotel_info() 함수 실행

    return 0;
}

int in_hotel_info(struct hotel_info *p){ // 해당 함수는 구조체 포인터를 받아 해당 배열의 크기를 리턴한다.
    int len = 0;
    // printf("debugging 1: method 1 starts\n");
    
    while (1)
    { 
        scanf("%s", p->name);// name을 검사
        if(strcmp(p->name, "0") == 0) break;// name이 0라면 반복문 종료
        // printf("debugging 2: successfully pass string line\n");
        scanf("%d %lf %lf %c", &(p->grade), &(p->rate), &(p->distance), &(p->breakfast));// 아니라면 나머지 값들 입력받기.
        getchar();// %c는 엔터를 삼키지 않기 때문에 엔터를 삼켜줄 함수가 별도로 필요. 이게 없다면 다음번 %s는 아무것도 저장되지 않는다.

        // printf("debugging: %s %d %.1lf %.1lf %c\n", p->name, p->grade, p->rate, p->distance, p->breakfast);
        p++;// 반복문을 종료하기 전에 해당하는 변수 값들을 조정
        len++;
    }
    

    return len;
}
void out_hotel_info(struct hotel_info *p, int n, int g, double d){
    // printf("out()=>debugging starts\n");
    struct hotel_info hotels[100]; // 가공한 값 출력을 위해 별도의 구조체 함수를 선언
    int i, hlen=0;// hotels 배열의 크기를 알아내기 위해 hlen 변수 선언과 동시에 0로 초기화, for loop controlling을 위한 변수 i 선언
    for(i=0;i<n; i++){
        // printf("out()=> dbg: %s's grade is %d, distance is %.1lf \n",(p+i)->name, p->grade, p->distance);
        if((p+i)->grade >= g && (p+i)->distance <= d){ //조건에 만족한다면
            *(hotels+hlen) = *(p+i);// hotels 배열에 저장
            hlen++;// 탐구한 배열 크기를 조정
        }
    }
    // printf("out()=>debugging : hlen is ... %d\n", hlen);
    struct hotel_info tmp;// swap을 위한 구조체 변수 tmp선언

    // for(i=0;i<hlen;i++)printf("dbg1 : %s\n", (hotels+i)->name);

    // sorting 정렬, 버블!
    int j;// 다중 for loop를 위한 j변수 선언
    for(i=0;i<hlen;i++){
        for(j=1;j<hlen;j++){
        //          j-1 j
            if(
            (hotels+j-1)->rate < (hotels+j)->rate                   // hotels 함수의 rate가 뒤에 있는 애가 더 크
                ||                                                  // 거나
                (hotels+j-1)->rate == (hotels+j)->rate && strcmp((hotels+j-1)->name , (hotels+j)->name ) >0// rate는 같은데 이름이 내림차순으로 정렬되어 있따면
            )
            {
                //swap을 진행
                tmp = *(hotels+j-1);
                *(hotels+j-1) = *(hotels+j);
                *(hotels+j) = tmp;
            }
        }
    }
    // 정렬이 완료된 뒤 결괏값들을 출력
    for(i=0;i<hlen;i++)printf("%s %d %.1lf %.1lf %c\n", (hotels+i)->name, (hotels+i)->grade, (hotels+i)->rate, (hotels+i)->distance, (hotels+i)->breakfast);
}
