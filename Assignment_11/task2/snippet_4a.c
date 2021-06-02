#include <stdlib.h>

#define N 7

int main() {

	int a[N] = { 0 };
	int b[N] = { 1 };
	int c[N] = { 2 };

	for(int i = 0; i < N; ++i) {
		if(N % 2) {
			a[i] = b[i] + 5;
		} else {
			a[i] = c[i] + 5;
		}
	}

	return EXIT_SUCCESS;
}