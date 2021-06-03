#include <stdlib.h>

#define N 7

int main() {

	int a[N] = { 7 };
    int min = a[0];
    int sum = a[0];

    for (int i = 1; i < N; ++i) {
        min = (a[i] < min) ? a[i] : min;
        sum += a[i];
    }

	return EXIT_SUCCESS;
}