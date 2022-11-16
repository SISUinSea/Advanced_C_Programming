#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// char *next(char *str, );

int main(){

}