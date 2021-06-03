#include <stdlib.h>

#define N 7
#define BLOCK_SIZE 64 / sizeof(double)

int main() {

	int a[N][N] = { 7 };
    int b[N][N] = { 2 };
    int c[N][N] = { 99 };

    for(int jj = 0; jj < N; jj += BLOCK_SIZE){
        for(int kk = 0; kk < N; kk += BLOCK_SIZE){
            for (int i = 0; i < N; ++i) {
                for (int j = jj; j < min(jj + BLOCK_SIZE, N); ++j) {
                    for (int k = 0; k < min(kk + BLOCK_SIZE, N); ++k) {
                        c[i][j] = a[i][k] * b[k][j];
                    }
                }
            }
        }
    }

	return EXIT_SUCCESS;
}