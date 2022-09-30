#include <stdio.h>
// check whether character is small alphabet.
int is_atoz(char c);
void PRT(int n, char *s);
int main() {
// set array ch' length as 100.
    char ch[100];
// pointer p will be used to control array. 
// firstIndex will save word's first address.
// maxFirstIndex will save longest word's first character index.
    char *p, *firstIndex, *maxFirstIndex;
// count will save word's length.
// maxCount will save longest word's lenght.
    int count, maxCount;
    count = maxCount = 0;
// get array data until the input is '#'. array's last element will always '#'.
    for (p = ch; ;p++){
        scanf("%c", p);
        if(*p == '#') break;
    }

// loop through ch array 
    for(p = ch; ; p++){
        if(*p == '#') break;

// if the array's element is small alphabet(a~z) increase count by 1.
        if(is_atoz(*p)) {
            printf("%c", *p);
            if(count == 0) firstIndex = p;
            count ++;
        }
// else test whether current count is max, and update max if so.
        else {
            if(is_atoz(*(p-1))){
                printf("\n");
                if(maxCount < count) {
                    // update maxCount and maxFirstIndex both.
                    maxCount = count;
                    maxFirstIndex = firstIndex;
                }
                // and set count to 0 again.
                count = 0;
            }
            // else{

            // }
        }
    }
    // printf("!!!right after exiting for loop, the *p is ...%c.!!!\n", *p);
// for the case that the last chracter is small alphabet, so the else block is not exectued.
// this will finally compare which is max.
    if(maxCount < count) {
        maxCount = count;
        maxFirstIndex = firstIndex;
    }
    if(is_atoz(*(p-1))) printf("\n");
// print results.
    printf("%d %c\n",maxCount, *maxFirstIndex);
    PRT(maxCount, maxFirstIndex);

    return 0;
}

/**
banana25apple#
*/
// check whether the character is small alphabet.
int is_atoz(char c){
    int result = 0;
    if(c >= 'a' && c <='z') result = 1;
    // if return value is 0, it means the character is not a small alphabet.
    // if return value is 1, it means the character is  a small alphabet.
    return result;
}


void PRT(int n, char *s){
// pointer p for control array.
    char *p;
// make for loop to print elements.
    for(p = s; p < s + n; p ++) printf("%c", *p);
    printf("\n");
}
