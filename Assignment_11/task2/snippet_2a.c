#include <stdlib.h>

#define N 7

int main() {

	int a[N] = { 0, 1, 2, 3, 4, 5, 6 };
	int b[N] = { 0 };
	int c[N] = { 0 };
	int d[N] = { 0 };
	int e[N] = { 0 };
	int f[N] = { 0 };

	for(int i = 1; i < N - 2; ++i) {
		b[i] = a[i - 1] + 1;
		c[i] = 2 * a[i];
		d[i] = a[i + 1] + 2;
		e[i + 1] = a[i + 2] + 3;
		f[i + 1] = e[i] + 4;
	}

	return EXIT_SUCCESS;
}