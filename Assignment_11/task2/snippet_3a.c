#include <stdlib.h>

#define N 7

int main() {

	double a[N] = { 0.0 };

	for(int i = 0; i < N; ++i) {
		a[i] *= hypot(0.3, 0.4);
	}

	return EXIT_SUCCESS;
}