#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {

	int A[N];
	int k = 0;

	// original variant
	for(int i = 4; i <= N; i += 7) {
		for(int j = 0; j <= N; j += 3) {
			A[i] = 0;
			printf("\nindex original: %d\n", i);
			++k;
		}
	}

	printf("\niterations original: %d\n", k);

	k = 0;

	// normalized variant
	for(int i = 0; i <= (N - 4) / 7; ++i) {
		for(int j = 0; j <= N / 3; ++j) {
			A[i + 4] = 0;
			printf("\nindex normalized: %d\n", i + 4);
			++k;
		}
	}

	printf("\niterations normalized: %d\n", k);

	k = 0;

	// even more normalized variant
	for(int i = 0; i <= (N * N - 4 * N) / 21; ++i) {
		A[(4 + N) - N / i] = 0;
		printf("\nindex normalized: %d\n", i + 4);
		++k;
	}

	printf("\niterations normalized: %d\n", k);

	return EXIT_SUCCESS;
}
