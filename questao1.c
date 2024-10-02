#include <stdio.h>
#include <math.h>

int primo(int n) {
    if(n <= 1){
       return 0;
    }else if(n == 2 || n == 3){
        return 1;
    }else if(n % 2 == 0 || n % 3 == 0){
        return 0;
    }else if(n <= sqrt(n)){
        return 1;
    }
}

int main() {
    int n;
    scanf("%i", &n);  
    if (primo(n)){
        printf("eh primo\n");
    }else {
        printf("nao eh primo\n");
    }

    return 0;
}