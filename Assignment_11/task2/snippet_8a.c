#include <stdlib.h>

#define N 2048

int main() {

	int a[N][N] = { 7 };
    int b[N][N] = { 2 };
    int c[N][N] = { 99 };

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c[i][j] = a[i][k] * b[k][j];
            }
        }
    }

	return EXIT_SUCCESS;
}