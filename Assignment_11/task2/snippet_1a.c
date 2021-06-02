#include <stdlib.h>

#define N 7

int main() {

	int a[N-1] = {0};
	int b[N] = {0, 1, 2, 3, 4, 5, 6};

	for(int i = 0; i < N - 1; ++i) {
		a[i] = b[i] + b[i + 1];
	}

	return EXIT_SUCCESS;
}