#include <stdio.h>
#include <string.h>
int main(){
    // full string will conducted with 200 characters.
    char str[200+1], str1[200];
    // seperated words will be saved in arr 2-demension array.
    char arr[20][200], tmp[200];
    // int for control for loop. len for get to know about str's len.
    int ai, aj, i,j,k, len;
    // int isExisted will be used as boolean. 0 means fales, other means true.
    int isExisted = 0;

    // get str value
    gets(str);
    // get str1 value
    gets(str1);

    // get str's length and save it len varaiable.
    for(len = 0; str[len]; len++);
    // puts(str);

    // checking already exist...
    // brutal force searching
    for(i = 0; str[i]; i++){
        // set boolean to 1
        isExisted = 1;
        for(j = 0, k = i; str[k]&&str1[j]; j++, k++){// k for controll str
        // and if one component is diff
            if(str[k]!=str1[j]){
                // change the bool to false and end the for loop
                isExisted = 0;
                break;
            }
        } 
        // when the bool is true,
        if(isExisted == 1){
            //break the for loop becuaes we already found the searching word
            break;
        }
    }
    if(!isExisted) {
        // if not exist, put the word behind of the string.
        strcat(str, " ");
        strcat(str, str1);
    }
    // puts(str);
    // seperating...
    for(i = 0, ai = 0, aj = 0; str[i]; i++){
        // ai aj for controlling the 2demension array. i for control string
        if(str[i]!=' '){
            // if the string's character is not space
            // put the word in to array to make word
            arr[ai][aj++] = str[i];
            // and print it
            printf("%c", str[i]);
        }else {
            // else (which is space)
            // end the word
            arr[ai++][aj] = '\0';
            // and ready to make another word
            aj = 0;   
            
            printf("\n");
        }
    }printf("\n");
    // end the word
    arr[ai++][aj] = '\0';



    // sorting...
    // bubble sorting
    for(int j = 1; j < ai ; j++){
        // Using nested for loop
        for(i = 1; i < ai; i++){
            // if the previous one is smaller than forward 
            if(strcmp(arr[i-1],arr[i]) > 0){
                // swap it
                strcpy(tmp, arr[i]);
                strcpy(arr[i], arr[i-1]);
                strcpy(arr[i-1], tmp);
            }
        }
    }

    // and assmeble it to one sentence sting
    strcpy(str,arr[0]);
    for(i = 1; i < ai; i++){
        strcat(str, " ");
        strcat(str, arr[i]);
    }
    // for(i = 0; i < ai ; i++)printf("%s ", arr[i]);
    // print sorted full sentence
    puts(str);
    return 0;
}