#include <stdio.h>
void gcdlcm(int a, int b, int *gcd, int *lcm);
int main() {
    int a, b;
    int gcd, lcm;

    scanf("%d %d", &a, &b);

    gcdlcm(a,b,&gcd,&lcm);

    printf("%d %d\n", gcd, lcm);
    return 0;
}

void gcdlcm(int a, int b, int *gcd, int *lcm){
    // 최대공약수
    int min, max; 
    // variable max will be used at finding Least common Multiple.
    int g; // greatest common factor
    
    if(a < b) 
    {
        min = a;
        max = b;
    }
    else 
    {
        min = b;
        max = a;
    }

    for (int i = min; i > 0; i--)
    {
        if(a%i==0 && b%i==0)
        {
            g = i;
            break;
        }
    }
    *gcd = g;
    

    // 최소공배수
    int testNumber = max;
    while (1)
    {
        if(testNumber%a==0 && testNumber%b==0)
        {
            *lcm = testNumber;
            break;
        }
        testNumber += max;
    }
    

}
