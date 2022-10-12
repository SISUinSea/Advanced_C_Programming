#include <stdio.h>
struct complex {
    double real, imag;
};
struct complex add(struct complex c1, struct complex c2);
int main() {
    struct complex c1, c2, result;
    scanf("%lf %lf", &c1.real, &c1.imag);
    scanf("%lf %lf", &c2.real, &c2.imag);
    // printf("%.2lf %.2lf", c1.real, c1.imag);
    result = add(c1, c2);
    printf("%.1lf + %.1lfi\n",result.real, result.imag);
    return 0;
}

struct complex add(struct complex c1, struct complex c2){
    double real, imag;
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
    struct complex result = {real, imag};
    return result;
}
