#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student {
    char *studentName;
    char id[4+1];
    char *subjectName;
    double subjectScore;
} st;

int main(){
    int n;scanf("%d", &n);getchar();
    st *stu = (st *) malloc(n*sizeof(st));
    if(!stu) {return -1;}

    int i;
    for(i = 0;i < n; i++) {
        char tmpStudent[100+1], tmpSubject[100+1];
        scanf("%s %s %s %lf", tmpStudent, (stu+i)->id, tmpSubject, &(stu+i)->subjectScore);
        (stu+i)->studentName = (char*)malloc((strlen(tmpStudent)+1) * sizeof(char));
        if(!((stu+i)->studentName)) {return -1;}
        (stu+i)->subjectName = (char*) malloc((strlen(tmpSubject)+1)*sizeof(char));
        if(!((stu+i)->subjectName)) {return -1;}
        strcpy((stu+i)->studentName, tmpStudent);
        strcpy((stu+i)->subjectName, tmpSubject);       
    }

    // for(i=0; i<n; i++) printf("---1 : %s %s %s %.2lf\n", (stu+i)->studentName, (stu+i)->id, (stu+i)->subjectName,(stu+i)->subjectScore);

//2 : sorting

    int j;
    for(i = 0; i< n; i++) {
        for(j = 1; j<n;j++) {
            if(stu[j-1].subjectScore < stu[j].subjectScore){
                st s = stu[j-1];
                stu[j-1] = stu[j];
                stu[j] = s;
            }
        }
    }

    int m;
    scanf("%d", &m);
    m--;
    printf("%s %s %s %.2lf\n", (stu+m)->studentName, (stu+m)->id, (stu+m)->subjectName, (stu+m)->subjectScore);

    for(i = 0; i<n; i++){
        free( (stu+i)->studentName );
        free( (stu+i)->subjectName );

    }
    free(stu);

    return 0;
}

