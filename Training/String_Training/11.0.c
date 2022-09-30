#include <stdio.h>
#include <string.h>

int main() {
    char str1[80+1], str2[10+1];
    scanf("%s", str1);
    scanf("%s", str2);

    int len1, len2, count = 0, isSame = 1;
    len1 = strlen(str1);
    len2 = strlen(str2);
    char *p, *p2, *p1;
    for(p = str1; p <= str1 + len1 - len2; p++){
        isSame = 1;
        for(p2 = str2, p1 = p; p2 < str2 + len2; p2 ++, p1++){
            if(*p1 != *p2){
                isSame = 0;
                break;
            }

        }
        if(isSame == 1) {
            count = 1;
            break;
        }
        
    }
    
    printf("%d ", len1);
    if(count == 1) printf("%d\n", count);
    else printf("0\n");

    

    
    return 0;
}


// brutal force search에서 pointer를 움직이는 규칙은 총 두 가지고, 그에 따른 특징도 다르게 나온다.
// 두가지 방법 모두 nested for loop에서 str1에 접근하기 위해 nesting for loop가 아닌 별도의 pointer를 사용해야 한다.
// default brutal force search는 str1의 요소 하나하나를 검사.
// jump brutal force search는 str1과 str2가 일치하는 경우 str2의 length만큼 건너뛰어 search.