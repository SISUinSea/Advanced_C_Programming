/*
lee1 2017102656 A
lee2 2018111823 A
park 2018059961 A
choi 2018010101 F
lee3 2019565656 B
park
*/

#include <stdio.h>
#include <string.h>
struct student {
    char name[9+1];
    char id[10+1];
    char score;
};
int main (){
    struct student students[5];
    int i;
    char searchWord[9+1];
    for(i = 0; i<5; i++){
        scanf("%s %s %c", students[i].name, students[i].id, &(students[i].score));
        getchar();
    }
    gets(searchWord);
    printf("\n");
    
    // for(i = 0; i<5; i++) 
    //     printf("%s %s %c\n", students[i].name, students[i].id, (students[i].score));

    for(i=0; i<5;i++){
        if( strcmp(searchWord, students[i].name) == 0){
            printf("%s %c", students[i].id, students[i].score);
        }
    }
    return 0;
}