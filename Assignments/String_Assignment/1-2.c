/*
Qej15J
SchOOL
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// decoder : decoding with input string & input number
void decoder(char *a, char *b, int n);
// change character by Capital rule.
char capital(char c, int n);
// change character by small rule.
char small(char c, int n);
// change character by int rule.
int toInt(char *c);
// main function begins
int main(){
    // declare strings with length 20 and its result 30 (because it can be repeated
    // n times when number is passed.
    char a[20+1], aResult[30+1];
    // make another string and string to save its result.
    char b[20+1], bResult[30+1];
    // make int value to seak available number
    int n;
    // get string a
    gets(a);
    // get string b
    gets(b);
// seak valid number starting with 1 to 10.
    for(n = 1; n <= 10; n++){
        // save a's result in aResult string.
        decoder(a,aResult, n);
        // save b's result in bResult string.
        decoder(b, bResult, n);
        // if b can be made with a
        if(strcmp(aResult, b)==0){
            //print 1
            printf("1\n");
            // and make program end.
            return 0;
        // if a can be made with b
        }else if( strcmp(bResult, a)==0 ){
            // print 2
            printf("2\n");
            // and exit program.
            return 0;
        }
    }
    // else print 0 and end program.
    printf("0\n");
    return 0;
}
//this method is the main feature of this program.
void decoder(char *a, char *b, int n){
    // i for control b string, j for get n times character to b
    int i=0,j;
    // p for control string with pointer
    char *p;
    // starting loop. until the a is not '\0'.
    for(p = a; *p ; p++){
        // if given character is capital alphabet
        if(*p >='A'&& *p <='Z'){
            // make b string with method capital and increase i by 1.
            *(b+i++) = capital(*p,n);
        }
        // if given character is small alphabet
        else if(*p >= 'a' && *p <= 'z'){
            // make b string with method small and increas i by 1.
            *(b+i++) = small(*p,n);
            
        }else if(*p >= '0' && *p <='9'){ // if given character is number
        // and if the previous already processed(it is number) continued it.
            if(*(p-1) >= '0' && *(p-1) <='9') continue;
            // make its result
            char result = 'A' + toInt(p) - 1;
            // and repeat it.
            for(j = 0; j < n;j++) 
                *(b+i++) = result;
        }else { // *p == ., !, ?, ...
        // else add ' ' to string b
            *(b+i++) = ' ';
        }
    }
    // the end of the string always be null character.
    *(b+i) = '\0';
}
// this is for changing character which is capital alphabet.
char capital(char c, int n){
    // change with its own rule
    return (c - 'A' + n)%26 + 'A';
}
// this is for changing character which is small alphabet.
char small(char c, int n){
        // change with its own rule
    return (c - 'a' - n)%26 + 'a';
}
// this is for changing character which is number charcater.
int toInt(char *c){
    // printf("c+1 is ...%c", *(c+1));
    // make a tmp character for not recoginzing the *c to array's first pointer.
    char tmp = *c;
    // make it int with atoi(stdlib.h) method.
    int result = atoi(&tmp);
    // printf("result is ...%d\n", result);
    // if the next character is also number, get that and combined it with making a hole number here. the next will be contiuned.
    if(*(c+1) >= '0' &&*(c+1) <= '9'){
        result*=10;
        result += atoi(c+1);
    }
    // return reulst value.
    return result;
}
