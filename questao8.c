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

int inverso_modular(int a, int m) {
		int x, y;
		int mdc = mdc_extendido(a, m, &x, &y);

		if (mdc != 1) {
				printf("o inverso modular não existe\n");
				return -1;
		}else{
				return (x % m + m) % m;
		}
}

void congruencia(int a, int b, int m) {
	int mdc = mdc_extendido(a, m, &a, &b);
	int inverso = inverso_modular(a, m);
	
	if (b % mdc != 0) {
			printf("a congruência não tem solução\n");
			return;
	}

	int x = (inverso * b) % m;
	if (x < 0) {
			x += m;
	}
	printf("x = %d\n", x);
}

int main() {
	int a, b, m;
	scanf("%d %d %d", &a, &b, &m);

	congruencia(a, b, m);

	return 0;
}