#include <omp.h>
#include <stdlib.h>

int main() {

	size_t n = 700;

	int a[n][n];
	int b[n][n];
	int c[n][n];

	for(size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j) {
			c[i][j] = a[i][j] * b[i][j];
		}
	}

	c[0][0]++;

	return EXIT_SUCCESS;
}