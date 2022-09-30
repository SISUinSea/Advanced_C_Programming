#include <stdio.h>

int main() {
    int d,i;
    scanf("%d", &d);

    char string[10];
    i=0;
    while (d > 0)
    {
        string[i++] = '0'+(d%10);
        // string[i++] = '0'+(d%10); 는 왜 안 될까?
        d/=10;
        i++;
    }
    

    printf("%s", string);
    
    return 0;
}