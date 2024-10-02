#include <stdio.h>

int algoritmo_euclides(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a; 
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    int mdc = algoritmo_euclides(a, b);
    
    printf("MDC: %d\n", mdc);
    
    return 0;
}

