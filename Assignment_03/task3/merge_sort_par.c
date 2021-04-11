/**
 * following code is based of:
 * https://www.techiedelight.com/iterative-merge-sort-algorithm-bottom-up/
 * (accessed: 10/04/2021)
 */

#include <limits.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000

void mergesort();
void merge();
int min();
void print_array();
int is_sorted();

int main() {
	int32_t array[N];
	int32_t temp[N];

	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		temp[i] = array[i] = (rand() % INT_MAX);
	}

	double start_time = omp_get_wtime();
	mergesort(array, temp);
	double end_time = omp_get_wtime();

	printf("\ntried to sort array in %2.6f\n", (float)end_time - start_time);

	if(is_sorted(array)) {
		printf("\nthe array is sorted\n");
	} else {
		printf("\nthe array is not sorted\n");
	}

	return EXIT_SUCCESS;
}

void mergesort(int32_t array[], int32_t temp[]) {
	for(int subarray_size = 1; subarray_size <= N - 1; subarray_size *= 2) {
#pragma omp parallel for schedule(static)
		for(int subarray_start = 0; subarray_start < N - 1; subarray_start += 2 * subarray_size) {
			int start = subarray_start;
			int middle = subarray_start + subarray_size - 1;
			int end = min(subarray_start + 2 * subarray_size - 1, N - 1);
			merge(array, temp, start, middle, end);
		}
	}
}

void merge(int32_t array[], int32_t temp[], int start, int middle, int end) {
	int array_index = start;
	int left_index = start;
	int right_index = middle + 1;

	while(left_index <= middle && right_index <= end) {
		if(array[left_index] < array[right_index]) {
			temp[array_index] = array[left_index];
			left_index++;
		} else {
			temp[array_index] = array[right_index];
			right_index++;
		}
		array_index++;
	}

	while(left_index < N && left_index <= middle) {
		temp[array_index++] = array[left_index++];
	}

	for(int i = start; i <= end; i++) {
		array[i] = temp[i];
	}
}

int min(int x, int y) {
	return (x < y) ? x : y;
}

void print_array(int32_t array[]) {
	for(int i = 0; i < N - 1; ++i) {
		printf("%d, ", array[i]);
	}
	printf("%d\n\n", array[N - 1]);
}

int is_sorted(int32_t array[]) {
	for(int i = 0; i < N - 1; ++i) {
		if(array[i] > array[i + 1]) {
			return 0;
		}
	}
	return 1;
}
