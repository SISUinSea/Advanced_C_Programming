/*
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct subject {
    char *name;
    double score;
} subject;
typedef struct student {
    char *name;
    char id[5];
    int numSubject;
    struct subject *psub;
    double avg;
} student;
int main(){
    int n;scanf("%d", &n); getchar();
    student *stu = (student *) malloc(n*sizeof(student));
    if(!stu) {return -1;}
    int i;
    char tmp[100+1];
    for(i = 0; i<n; i++) {
        gets(tmp);
        int cnt = 0;
        char *p;
        for(p = tmp; *p ; p++) if(*p == ' ') cnt++;
        stu[i].numSubject = (cnt-2) / 2;
        stu[i].psub = (subject *) malloc( stu[i].numSubject * sizeof(subject) );
        if(!stu[i].psub) {return -1;}
        // name
        cnt = 0;
        for(p = tmp; *p != ' '; p++)cnt++; 
        stu[i].name  = (char *) malloc((cnt+1)*sizeof(char));
        if(!stu[i].name){return -1;}
        strncpy(stu[i].name, (p)-cnt, cnt);
        // for(p = tmp; *p != ' ' && *p; p++){
        //     strcat(stu[i].name, p);
        // }
        printf("---1: name : %s \n", stu[i].name);
        // id
        cnt = 0;
        for(p = p+1; *p != ' '; p++) cnt ++;
        strncpy(stu[i].id, p-cnt, cnt);
        // printf("---1: id : %s\n", stu[i].id);

        // printf("---1 : name 1: %s \n", stu[i].name);

        cnt = 0;
        int pi = 0;
        //: subject & score
        for(p = p+1; *p;p++ ){
            // printf("---1 : name 2: %s \n", stu[i].name);
            if(*p != ' ') {
                cnt++;
            }else {
                char tmp1[2+1];

                stu[i].psub[pi].name = (char *) malloc((cnt+1)*sizeof(char));
                if(!stu[i].psub[pi].name) {return -1;}
                strncpy(stu[i].psub[pi].name, p-cnt, cnt);
                // puts(stu[i].psub[pi].name);
                cnt = 0;
                for(p = p+1; *p != ' ' && *p; p++) cnt++;
                // printf("---2.0: current cnt is %d\n", cnt);
                strncpy(tmp1, p-cnt, cnt);
                stu[i].psub[pi].score = (double)atoi(tmp1);
                // printf("---2 : %s %.2lf\n",stu[i].psub[pi].name, stu[i].psub[pi].score);
                cnt = 0;
                pi++;
            }
        }
                // printf("---1 : name 3: %s \n", stu[i].name);

        // printf("\n---2: %s\n", stu[i].name);

    }

    for(i = 0; i< n; i++) {
        stu[i].avg = 0;
        for(int j = 0; j < stu[i].numSubject; j++){
            stu[i].avg += stu[i].psub[j].score;
        }
        stu[i].avg /= stu[i].numSubject;
    }

    for(i = 0 ; i< n; i++) printf("%s %s %s \n", (stu+i)->name, stu[i].id, stu[i].psub[0].name);
}

