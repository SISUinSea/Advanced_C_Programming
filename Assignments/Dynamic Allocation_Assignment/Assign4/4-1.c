/*
7 3
Kim 75 85
Lee 96 56
Park 94 82
Choi 78 70
Jung 65 85
Kang 93 63
Cho 93 63
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct student {
    char *name;
    int firstStage;
    int interview;
    double sum;
} student;
int main (){
    int n, m;scanf("%d %d", &n, &m);
    getchar();

    student *s = (student *) malloc(n * sizeof(student));
    if(!s) {return -1;}

    int i, cnt;
    char str[18+1],tmp[3+1];
    char *p;
    for(i = 0; i< n; i++) {
        cnt = 0;
        gets(str);
        for(p=str; *p!=' ';p++) cnt++;
        (s+i)->name = (char *) malloc((cnt+1) * sizeof(char));
        if(!(s+i)->name) {return -1;}
        strncpy((s+i)->name, str, cnt);
        // puts((s+i)->name);

        cnt = 0;
        for(p = p+1; *p!=' '; p++) cnt++;
        strncpy(tmp, p-cnt, cnt);
        (s+i)->firstStage = atoi(tmp);

        cnt = 0;
        for(p = p+1; *p; p++) cnt++;
        strncpy(tmp, p-cnt, cnt);
        (s+i)->interview = atoi(tmp); 
        (s+i)->sum = (s+i)->firstStage * 7 + (s+i)->interview * 3;
    }

    int j;
    for(i  =0; i<n; i++) {
        for(j = 1; j<n; j++) {
            if( (s+j-1)->sum < (s+j)->sum 
                ||
                (s+j-1)->sum == (s+j)->sum && (s+j-1)->firstStage < (s+j)->firstStage
                || 
                (s+j-1)->sum == (s+j)->sum && (s+j-1)->firstStage == (s+j)->firstStage && strcmp((s+j-1)->name , (s+j)->name) > 0){
                student swapV = *(s+j-1);
                *(s+j-1) = *(s+j);
                *(s+j) = swapV;
            }
        }
    }
    // for(i = 0; i<n; i++) printf("---1 : %s %d %d %.1lf\n", (s+i)->name, (s+i)->firstStage, (s+i)->interview, (s+i)->sum/10);
    // for(i = 0; i<n; i++) printf("%s %d %d %.1lf\n", (s+i)->name, (s+i)->firstStage, (s+i)->interview, (s+i)->sum/10);

    int endCount = 0;
    int total = 0;
    for(endCount = 0; endCount < m; total++){
        // if(endCount != 0 && (s+endCount-1)->sum == (s+endCount)->sum 
        //     && 
        //     (s+endCount-1)->firstStage == (s+endCount)->firstStage
        //     ){
        //         printf("--- endcount = %d %s %.1lf\n",endCount, (s+endCount)->name, (double)(s+endCount)->sum /10);
        //     }
        // else {
        //     printf("else --- endcount = %d %s %.1lf\n",endCount, (s+endCount)->name, (double)(s+endCount)->sum /10);
        //     endCount ++;
        // }
        printf("--- endcount = %d %s %.1lf\n",endCount, (s+endCount)->name, (double)(s+endCount)->sum /10);

        if((s+endCount)->sum == (s+endCount+1)->sum 
            && 
            (s+endCount)->firstStage == (s+endCount+1)->firstStage) endCount++;
    }
    for(i = 0; i< n; i++) free((s+i)->name);
    free(s);

}