#include <stdio.h>
#include <string.h>
typedef struct student {
    char name[9+1];
    char id[10+1];
    char grade; // A, B, F

} ST;

int main(){
    ST st[5];
    char searchingName[9+1];
    int i;
    for(i = 0; i<5; i++) {
        scanf("%s %s %c", (st+i)->name, (st+i)->id, &(st+i)->grade);
        getchar();
    }

    gets(searchingName);

    for(i = 0; i < 5; i++) {
        if(strcmp(searchingName, (st+i)->name) == 0) {
            printf(" %s %c\n", (st+i)->id, (st+i)->grade);
            break;
        }
    }
}