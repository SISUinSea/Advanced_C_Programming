#include <stdio.h>
#include <string.h>

int main(){
    // make array for saving string value
    char str1[100], str2[100];

    // make array for saving word. this will be 2demension array.
    char arr[50][100];
    // int for saving value and controlling for loop
    int i, ai, aj, count = 0;
    // get str1 string
    gets(str1);
    // get str2 string
    gets(str2);
    // seperating words...
    // ai, aj for controlling 2 demension array.
    // i for conrotlling str1 string
    for(i = ai = aj = 0; str1[i]; i++){
        // if the str1's element is not . and  ,
        if(str1[i]!=' ' && str1[i]!='.'){
            // put the character to make word
            arr[ai][aj++] = str1[i];
        }else {
            // else if the . or  is successive, contiued it
            if(str1[i-1]==' ' || str1[i-1]=='.') continue;
            // else end the word and get ready to save new word.
            arr[ai++][aj] = '\0';
            aj = 0;
        }
    }//end the word
    arr[ai++][aj] = '\0';
    // for(i = 0; i < ai ; i++) printf("%s\n", arr[i]);
    // make compare both are same word by word using 2demension array
    for(i = 0; i < ai; i++){
        // if some words are same with str2 increase count variable by 1.
        if(strcmp(arr[i],str2)==0){
            count ++;
        }
    }

// print count variable
    printf(
        "%d\n", count
    );

    return 0;
}