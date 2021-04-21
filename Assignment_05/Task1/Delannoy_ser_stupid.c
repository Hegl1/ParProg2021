#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


long calculate_delanoy(int m, int n){
    if(m == 0 || n == 0){
        return 1;
    } else{
        return calculate_delanoy(m-1, n) + calculate_delanoy(m-1, n-1) + calculate_delanoy(m, n-1);
    }
}

int main(int argc, char** argv){

    int problem_size;

    if(argc < 2){
        printf("usage: ./delannoy_stupid.out <gridsize>\n");
        return EXIT_FAILURE;
    } else {
        problem_size = atol(argv[1]);
    }

    #ifdef TIME
    double start_time = omp_get_wtime();
    calculate_delanoy(problem_size, problem_size);
    double end_time = omp_get_wtime();
    printf("time: %2.9f \n",end_time-start_time);
    #endif

    #ifndef TIME
        printf("delanoy number for given input: %ld\n", calculate_delanoy(problem_size, problem_size));
    #endif
}

