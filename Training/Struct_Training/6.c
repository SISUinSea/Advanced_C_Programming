/*
2
1 66 170
2 48 155 
*/

#include <stdio.h>
struct student {
    int sex, weight, height;
};
int main() {
    int grade1, grade2, grade3;
    grade1 = grade2 = grade3 = 0;
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        struct student s;
        scanf("%d %d %d",&s.sex, &s.weight, &s.height);
        if(s.sex == 1){
            // male
            if(s.weight <60){
                if(s.height < 165) grade1++;
                else if(s.height >= 165 && s.height <175) grade2++;
                else if(s.height >= 175) grade3++;
            }else if(s.weight >= 60 && s.weight <70){
                if(s.height < 165) grade3++;
                else if(s.height >= 165 && s.height <175) grade1++;
                else if(s.height >= 175) grade2++;
            }else if(s.weight >= 70){
                if(s.height < 165) grade2++;
                else if(s.height >= 165 && s.height <175) grade3++;
                else if(s.height >= 175) grade1++;
            }

        }else {
            // female
            if(s.weight <60-10){
                if(s.height < 165) grade1++;
                else if(s.height >= 165 && s.height <175) grade2++;
                else if(s.height >= 175) grade3++;
            }else if(s.weight >= 60-10 && s.weight <70-10){
                if(s.height < 165) grade3++;
                else if(s.height >= 165 && s.height <175) grade1++;
                else if(s.height >= 175) grade2++;
            }else if(s.weight >= 70-10){
                if(s.height < 165) grade2++;
                else if(s.height >= 165 && s.height <175) grade3++;
                else if(s.height >= 175) grade1++;
            }
        }
    }
    printf("%d %d %d\n", grade1, grade2, grade3);
    return 0;
}