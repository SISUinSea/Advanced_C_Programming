#include <stdio.h>
#include <string.h>

int main() {
    char a[6], b[6];
    char *pa=&a, *pb=&b;

    for(pa = a; pa < a + 6; pa++)
    {
        scanf("%c", pa);
    }

    strcpy(pb, pa);

    puts(b);
    printf("\n");

    return 0;
}