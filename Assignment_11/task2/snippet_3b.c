#include <stdlib.h>

#define N 7

int main() {

	double a[N] = { 0.0 };

	double hyptenuse = hypot(0.3, 0.4);
		
	for(int i = 0; i < N; ++i) {
		a[i] *= hypotenuse;
	}

	return EXIT_SUCCESS;
}