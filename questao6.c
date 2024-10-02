#include <stdio.h>

int algoritmo_euclides_estendido(int a, int b, int *s, int *t) {
    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }

    int s1, t1;  
    int mdc = algoritmo_euclides_estendido(b, a % b, &s1, &t1);

    *s = t1;
    *t = s1 - (a / b) * t1;

    return mdc;
}

int main() {
    int a, b;
 
    scanf("%d %d", &a, &b);
    
    int s, t;
    
    int mdc = algoritmo_euclides_estendido(a, b, &s, &t);
    

    printf("MDC(%d, %d) = %d\n", a, b, mdc);
    printf("Coeficiente s: %d\n", s);
    printf("Coeficiente t: %d\n", t);
    
    return 0;
}


