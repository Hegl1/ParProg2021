#include <stdlib.h>

#define N 7

int main() {

	int a[N - 1] = { 0 };
	int b[N] = { 0, 1, 2, 3, 4, 5, 6 };

    a[0] = b[0] + b[1];    
    a[1] = b[1] + b[2];
    a[2] = b[2] + b[3];
    a[3] = b[3] + b[4];
    a[4] = b[4] + b[5];
    a[5] = b[5] + b[6];
    a[6] = b[6] + b[7];    

    return EXIT_SUCCESS;
}