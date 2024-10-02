#include <stdio.h>
#include <math.h>

int ehPrimo(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void fatorar(int num, int primos[], int potencias[], int* tamanho) {
    int fator = 2;
    *tamanho = 0;
    
    while (num > 1) {
        if (ehPrimo(fator) && num % fator == 0) {
            int cont = 0;
            while (num % fator == 0) {
                num /= fator;
                cont++;
            }
            primos[*tamanho] = fator;
            potencias[*tamanho] = cont;
            (*tamanho)++;
        }
        fator++;
    }
}

int calcularMDC(int primos1[], int potencias1[], int tamanho1, int primos2[], int potencias2[], int tamanho2) {
    int mdc = 1;
    for (int i = 0; i < tamanho1; i++) {
        for (int j = 0; j < tamanho2; j++) {
            if (primos1[i] == primos2[j]) {
                int minPotencia = (potencias1[i] < potencias2[j]) ? potencias1[i] : potencias2[j];
                mdc *= pow(primos1[i], minPotencia);
            }
        }
    }
    return mdc;
}

int calcularMMC(int primos1[], int potencias1[], int tamanho1, int primos2[], int potencias2[], int tamanho2) {
    int mmc = 1;
    int i = 0, j = 0;
    
    while (i < tamanho1 || j < tamanho2) {
        if (i < tamanho1 && (j >= tamanho2 || primos1[i] < primos2[j])) {
            mmc *= pow(primos1[i], potencias1[i]);
            i++;
        } else if (j < tamanho2 && (i >= tamanho1 || primos2[j] < primos1[i])) {
            mmc *= pow(primos2[j], potencias2[j]);
            j++;
        } else {  // primos1[i] == primos2[j]
            int maxPotencia = (potencias1[i] > potencias2[j]) ? potencias1[i] : potencias2[j];
            mmc *= pow(primos1[i], maxPotencia);
            i++;
            j++;
        }
    }
    
    return mmc;
}

int main() {
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
     
    int primos1[100], potencias1[100], tamanho1;
    int primos2[100], potencias2[100], tamanho2;
  
    fatorar(num1, primos1, potencias1, &tamanho1);
    fatorar(num2, primos2, potencias2, &tamanho2);
    
    int mdc = calcularMDC(primos1, potencias1, tamanho1, primos2, potencias2, tamanho2);
    int mmc = calcularMMC(primos1, potencias1, tamanho1, primos2, potencias2, tamanho2);

    printf("MDC(%d, %d) = %d\n", num1, num2, mdc);
    printf("MMC(%d, %d) = %d\n", num1, num2, mmc);
    
    return 0;
}


