#include <stdio.h>
int arrsum(int *ps, int* pe);
int main() {
    int n, s, e;
    int *p;
    scanf("%d %d %d", &n, &s, &e);

    int arr[n];
    for(p = arr; p < arr+n; p++)
    {
        scanf("%d", p);
    }

    printf("%d", arrsum(arr+s, arr+e));

    return 0;
}
int arrsum(int *ps, int* pe){
   int *p, result = 0; 
   for(p = ps; p <= pe; p++)
   {
    result += *p;
   }
   return result;
}
