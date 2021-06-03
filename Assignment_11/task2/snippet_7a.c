#include <stdlib.h>

#define N 7

int main() {

	int a[N] = { 7 };
    int b[N] = { 2 };
    int c[N] = { 99 };

    for (int i = 0; i < N; ++i) {
        if (i % 2) {
            a[i] = b[i] + 4;
        } else {
            a[i] = c[i] + 5;
        }
    }

	return EXIT_SUCCESS;
}