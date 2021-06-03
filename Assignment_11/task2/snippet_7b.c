#include <stdlib.h>

#define N 7

int main() {

	int a[N] = { 7 };
    int b[N] = { 2 };
    int c[N] = { 99 };

    a[0] = c[0] + 5;
    for (int i = 2; i < N; i+=2) {
            a[i] = b[i] + 4;
    }

    for (int i = 1; i < N; i+=2) {
            a[i] = c[i] + 5;
    }

	return EXIT_SUCCESS;
}