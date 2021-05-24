#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 6
#define M 4

int main() {

	int a[N][M];
	int b = 5;

	// -------------- original -------------

	// initialize array
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			a[i][j] = i + j * 5;
		}
	}

	// juggle array
	double start_time_seq = omp_get_wtime();
	for(int i = 0; i < 4; ++i) {
		for(int j = 1; j < 4; ++j) {
			a[i + 2][j - 1] = b * a[i][j] + 4;
		}
	}
	double end_time_seq = omp_get_wtime();

	// -------------- parallelized -------------

	// initialize array
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			a[i][j] = i + j * 5;
		}
	}

	// juggle array
	double start_time_par = omp_get_wtime();
#pragma omp parallel
	{
#pragma omp single
		{
#pragma omp task
			{
				for(int i = 0; i < 2; ++i) {
					for(int j = 1; j < 4; ++j) {
						a[i + 2][j - 1] = b * a[i][j] + 4;
					}
				}
			}

#pragma omp task
			{
				for(int i = 2; i < 4; ++i) {
					for(int j = 1; j < 4; ++j) {
						a[i + 2][j - 1] = b * a[i][j] + 4;
					}
				}
			}
		}
	}
	double end_time_par = omp_get_wtime();

	printf("sequential time: %lf\n", end_time_seq - start_time_seq);
	printf("parallel time: %lf\n", end_time_par - start_time_par);

	return EXIT_SUCCESS;
}