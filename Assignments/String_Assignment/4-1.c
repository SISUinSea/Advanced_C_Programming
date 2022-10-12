/*
3
2 9
ClanguageIsInteres  ting
CCC  CCCC
LanguageC
*/

#include <stdio.h>
//  s_check method for check how many small alphabet is exist and return the number of them.
int s_check(char *p, char *q);
int main(){
// declare variable m, k1, k2 for passed data from user.
// declare count, i variable for saving and controlling data  
    int m,k1,k2, count,i;
    // decalre string str 
    char str[200];
    // get data from user
    scanf("%d", &m);
    scanf("%d %d", &k1, &k2);
    // throw away trash data to save under gets() method from trash enter data
    getchar();
    // printf("Im here!!!!!\n");
    // printf( "m, k1 and k2 is ...%d %d %d\n",m,k1, k2);
    // for loop will be repeated m times
    for(i = 0; i < m; i++){
        // printf("!!!!!!!!!!!!index : %d!!!!!!!!\n", i);
        // get str from user
        gets(str);
        // save s_check's return value to count
        count = s_check(str+k1, str+k2);
        // if count is not 0, print count varable
        if(count) printf("%d\n", count);
    }
    
    return 0;
}
// this method is counting how many small alphabet is located in the string
int s_check(char *p, char *q){
    // declare a pointer for controlling for loop.
    char *c;
    int count=0;
    // count will be returned. set count variable to 0.
    for(c = p; c <= q && *c; c++)
    // if the character is small alphabet, increase count by 1.
        if(*c>='a'&& *c<='z') count++;
    // return count;
    return count;
}


