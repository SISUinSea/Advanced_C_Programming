/*
4
1111 12345678 S N 7 230
2222 22223333 D 240
3333 44445555 D 255
4444 66667777 S Y 30 200

6
3777 28171652 S Y 30 348
1989 97027706 D 429
7757 25158262 S Y 30 392
2714 15392245 D 560
8506 12389677 D 47
5113 59262609 S N 30 967
*/

#include <stdio.h>
struct parking_info{
    int carNumber, phoneNumber;
    char item;// S or D
    char alreadyS; // Y or N
    int registrationLength; // how long will you use the parking lot?
    int parkingTime;
    double charge; // total fee you should pay
};

void input(struct parking_info *p, int n);
void compute(struct parking_info *p);
void display(struct parking_info *p, int n);
void parking_info_sort(struct parking_info *p, int n);

int main() {
    struct parking_info parkData[100]; // parking_info struct 배열 parkData를 선언

    int n, i;// 차량 횟수를 설정할 n 변수 선언, for loop controlling을 위한 변수 i 선언
    scanf("%d", &n);// 값 입력받아 n에 저장
    input(parkData, n);// input()함수를 실행
    for(i=0;i<n;i++) compute(parkData+i); // for loop 안에서 each parkDatum마다 compute() 함수 실행
    // display(parkData, n);
    parking_info_sort(parkData, n); // parking_info_sort()함수를 통해 문제에서 제시한 대로 정렬 후 결과값 출력
    return 0;
}

void input(struct parking_info *p, int n){
    int i; // for loop controlling을 위한 변수 i 선언
    // printf("input()=> debugging starts\n");
        
    for(i=0;i<n;i++) {
        scanf("%d %d %c", &(p+i)->carNumber, &(p+i)->phoneNumber, &(p+i)->item);// 기본 값들을 넘겨 받기
        getchar(); // for taking away ' '. 이게 꼭 필요한가? %c %c가 있을 때에도?
        if((p+i)->item == 'S'){// 만약 D/S 중 고객이 S라면
            scanf("%c %d %d", &(p+i)->alreadyS, &(p+i)->registrationLength, &(p+i)->parkingTime);// 다음과 같은 정보를 입력받아 저장
        }
        else{// 아니면 기본 주차 시간 정보만 입력받아 저장
            scanf("%d", &(p+i)->parkingTime);
        }
    }

    // debugging lines 

    // printf("input()=>debugging 2\n");
    // for(i=0;i<n;i++) {
    //     printf("===============\n");
    //     printf("car Number is... %d\nphone number is... %d\n(S/D) %c\n",(p+i)->carNumber, (p+i)->phoneNumber, (p+i)->item);
    //     if((p+i)->item == 'S'){
    //         printf("already registrated?:%c\nhow long?: %d\n", (p+i)->alreadyS, (p+i)->registrationLength);
    //     }
    //     printf("parking Time: %d\n", (p+i)->parkingTime);
    //     printf("===============\n");
    // }
    

}
void compute(struct parking_info *p){
    int total=0; // parking_info struct의 charge 변수에 저장할 값을 만들기 위해 total 변수를 선언하고 0로 초기화. 필요한 값들을 더해나갈 것이다.
    if(p->item=='S'&&p->alreadyS=='N'){// 만약 S에 가입하지 않았고 가입을 희망하는 고객이라면
        switch (p->registrationLength){// registrationLength 에 따라 가격 차등 적용
            case 7:// 7일일 때 30000원
                total+=30000;
                break;
            case 30:// 한 달일 때 1000000원
                total+=100000;
                break;
            case 180:// 6개월일 때 50만원을 가격에 추가
                total+=500000;
                break;
        }
    }else if(p->item=='D'){// S가입을 희망하지 않는 D라면
        total += 5000;// 기본요금 5000원 청구
    }

    if(p->parkingTime > 240){// parkingTime이 4시간을 넘어간다면
        total += (p->parkingTime -240)/10 * 200; // 10분 초과당 200원 받기
    }

    p->charge = total;// 해당하는 struct의 change 변수에 total값을 넘겨주기

    // printf("compute()=>: charge:%.1lf\n",p->charge);
}
// void display(struct parking_info *p, int n){
//     int i; //for loop controlling을 위한 변수 i 선언
//     for(i=0;i<n;i++){
//         printf("%d %d %c %.0lf\n", (p+i)->carNumber, (p+i)->phoneNumber, (p+i)->item, (p+i)->charge);
//     }
// }
void parking_info_sort(struct parking_info *p, int n){
    struct parking_info dUser[100], sUser[100];
    int i,j; //for loop controlling을 위한 변수 i,j 선언
    int di,si;// dUser, sUser 배열의 크기를 알기 위해 di, si 변수를 선언 후 0으로 초기화
    di=si=0;
        // 고객이 S인지 D인지를 검사 후 각각의 배열에 저장하기
    for(i=0;i<n;i++){
        if((p+i)->item == 'D'){
            *(dUser+di++) = *(p+i);
        }else{
            *(sUser+si++) = *(p+i);
        }
    }

    // for(i=0;i<di;i++)printf("sorting()=>: %d %d %c %.0lf\n", (sUser+i)->carNumber, (sUser+i)->phoneNumber, (sUser+i)->item, (sUser+i)->charge);
        // 각 배열을 정렬하기.
    struct parking_info tmp;// swap을 위한 변수 tmp 선언
    for(i=0;i<di;i++){
        for(j=1;j<di;j++){
            if( (dUser+j-1)->carNumber >  (dUser+j)->carNumber){// 앞에 있는 고객보다 뒤에 있는 고객의 차 번호가 정수 순서상 더 앞이라면
            //  swap을 진행
                tmp = *(dUser+j-1);
                *(dUser+j-1) = *(dUser+j);
                *(dUser+j) = tmp;
            }
        }
    }
    for(i=0;i<si;i++){
        for(j=1;j<si;j++){
            if( (sUser+j-1)->carNumber >  (sUser+j)->carNumber){// 앞에 있는 고객보다 뒤에 있는 고객의 차 번호가 정수 순서상 더 앞이라면
            //  swap을 진행
                tmp = *(sUser+j-1);
                *(sUser+j-1) = *(sUser+j);
                *(sUser+j) = tmp;
            }
        }
    }
    // 결과값들을 출력
    for(i=0;i<di;i++)printf("%d %d %c %.0lf\n", (dUser+i)->carNumber, (dUser+i)->phoneNumber, (dUser+i)->item, (dUser+i)->charge );
    for(i=0;i<si;i++)printf("%d %d %c %.0lf\n", (sUser+i)->carNumber, (sUser+i)->phoneNumber, (sUser+i)->item, (sUser+i)->charge );

    // 총 금액 산출을 위한 
    double dCharge, sCharge; // 변수 선언
    dCharge = sCharge = 0;// 0으로 초기화
    for(i=0;i<di;i++) dCharge += (dUser+i)->charge;// dUser에서 총 금액을 더하기
    for(i=0;i<si;i++) sCharge += (sUser+i)->charge;// sUser에서 총 금액을 더하기
    printf("%.0lf %.0lf %.0lf\n", dCharge, sCharge, dCharge+sCharge);// 결괏값 출력
}

