#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1024

void copy();
void print_array();

int main() {

	double x[N];
	double y[N];

	for(int i = 0; i < N; i++) {
		x[i] = i;
		y[i] = 0;
	}

	double start_time = omp_get_wtime();
#pragma omp parallel
	{
#pragma omp for schedule(static)
		for(int i = 0; i < 1024; i++) {
			y[i] = x[i];
		}
	}
	double end_time = omp_get_wtime();

	printf("\n time: %lf\n", end_time - start_time);

	return EXIT_SUCCESS;
}

void print_array(double* x) {
	printf("\n");
	for(int i = 0; i < N - 1; i++) {
		printf("%lf, ", x[i]);
	}
	printf("%lf\n", x[N - 1]);
}
