#include <stdio.h>


int mdc_extendido(int a, int b, int *x, int *y) {
		if (b == 0) {
				*x = 1;
				*y = 0;
				return a;
		}

		int x1, y1;
		int mdc = mdc_extendido(b, a % b, &x1, &y1);

		*x = y1;
		*y = x1 - (a / b) * y1;

		return mdc;
}

int inverso_modular(int a, int b) {
		int x, y;
		int mdc = mdc_extendido(a, b, &x, &y);

		if (mdc != 1) {
				printf("o inverso modular não existe\n");
				return -1;
		}else{
				int resultado = (x % b + b) % b;
				return resultado;
		}
}

int main() {
		int a, b;

		scanf("%d %d", &a, &b);

		int inverso = inverso_modular(a, b);

		if (inverso != -1) {
				printf("o inverso de %d mod %d é: %d\n", a, b, inverso);
		}

		return 0;
}