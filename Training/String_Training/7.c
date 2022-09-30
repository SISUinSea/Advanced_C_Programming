#include <stdio.h>
#include <stdlib.h>

int main() {
    char alphabet[10][6] = {"","one","two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char volum[4][3+1] = {"", "TEN", "HUN", "THO"};

    int count = 0, processed, n, i, ten = 1;
    scanf("%d", &n);

    for(processed = n; processed > 0; processed/=10) count++;

    for(; n > 0; n%=ten, count--){
        ten = 1;
        for(i = count-1; i > 0; i--) ten*=10;
        processed = n/ten;
        if(processed != 0) printf("%s %s ",alphabet[processed],volum[count-1]);
    }
    
    return 0;
}