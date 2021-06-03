#include <stdlib.h>

#define N 7

int main() {

	int a[N] = { 7 };
    int min = a[0];
    int sum = 0;

    for (int i = 1; i < N; ++i) {
        min = (a[i] < min) ? a[i] : min;
    }
    for (int i = 0; i < N; ++i) {
        sum += a[i];
    }

	return EXIT_SUCCESS;
}