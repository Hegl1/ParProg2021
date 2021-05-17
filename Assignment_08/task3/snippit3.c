#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3
#define L 3

void print_array();

int main() {

	int a[N][M][L];
	int x = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			for(int k = 0; k < L; k++) {
				a[i][j][k] = ++x;
			}
		}
	}

	print_array(a);

	for(int i = 1; i < N; i++) {
		for(int j = 1; j < M; j++) {
			for(int k = 1; k < L; k++) {
				a[i + 1][j][k - 1] = a[i][j][k] + 5;
			}
		}
	}

	print_array(a);

	printf("\ndebug 20\n");
	return EXIT_SUCCESS;
}

void print_array(int array[N][M][L]) {

	printf("\narray:\n");
	for(int i = 0; i < N; i++) {
		printf("\nlayer %d: \n", i);
		for(int j = 0; j < M; j++) {
			for(int k = 0; k < L; k++) {
				printf("%d ", array[i][j][k]);
			}
			printf("\n");
		}
	}
	printf("\ndebug 10\n");
}