/*1900000000
Task1 Threads : 1; -O3
Time: 2.46582
Task1 Threads : 4; -O3
Time: 0.78841
*/

#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Error: usage: %s <n>\n", argv[0]);
		return EXIT_FAILURE;
	}
	char *str = argv[1];
	char *endptr;
	long n = strtol(str, &endptr, 0);

    volatile int inc = 0;
    double time;

    double start_time = omp_get_wtime();
    #pragma omp parallel proc_bind(spread)
		#pragma omp parallel proc_bin(close)
        	#pragma omp for
		    	for (long i = 0; i < n; i++) {
			    	inc++;
		    	}

    double end_time = omp_get_wtime();

    time = end_time - start_time;
    printf("\nTime: %2.2f", time);
}