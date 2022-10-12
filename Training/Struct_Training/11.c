/*
akim 75
bkim 85
ckim 65 
dkim 95
ekim 100
*/

#include <stdio.h>
struct student {
    char name[9+1];
    int score;
};
struct student* select_min(struct student *students);
int main() {
    struct student students[5], *minStudent;

    for(int i=0; i<5; i++) scanf("%s %d",students[i].name, &students[i].score);
    // for(int i=0; i<5; i++) printf("%s %d\n",students[i].name, students[i].score);
    minStudent = select_min(students);
    printf("%s %d\n", (*minStudent).name, (*minStudent).score);
    return 0;
}

struct student* select_min(struct student *students){
    int minScore = 100;
    struct student *minScoreStudent = students+0;

    for(int i=0; i<5; i++){
        if(minScore > (* (students+i) ).score ) {
            minScore = (* (students+i) ).score;
            minScoreStudent = (students+i);
        }
    }
    return minScoreStudent;
}
