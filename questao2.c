#include <stdio.h>
#include <math.h>
#include <time.h>

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
    
    time_t start_time = time(NULL);
    int n = 2;

    while(difftime(time(NULL), start_time) < 60) {
        if(primo(n)){
            printf("%d\n", n);
        }
        n++;
    }

    return 0;

}