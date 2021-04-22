#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define PAR_BORDER 8

long calculate_delanoy(int m, int n){
   
    
    if(m == 0 || n == 0){
        return 1;
    } else{

        if(m < PAR_BORDER || n < PAR_BORDER){
            return calculate_delanoy(m-1, n) + calculate_delanoy(m-1, n-1) + calculate_delanoy(m, n-1);
        }else{
            long i, j, k;

        #pragma omp task shared(i)
            i = calculate_delanoy(m-1, n);

        #pragma omp task shared(j)
            j = calculate_delanoy(m-1, n-1);
        
            k = calculate_delanoy(m, n-1);
        
        #pragma omp taskwait
            return  i+j+k;
        }

    }
    
}

int main(int argc, char** argv){
    int problem_size;
    if(argc < 3){
        printf("usage: ./delannoy_stupid.out <gridsize> <num_threads>\n");
        return EXIT_FAILURE;
    } else {
        problem_size = atol(argv[1]);
        omp_set_num_threads(atol(argv[2]));
    }

    #ifdef TIME
    double start_time = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        calculate_delanoy(problem_size, problem_size);
    }

    double end_time = omp_get_wtime();
    printf("time: %2.9f \n",end_time-start_time);
    #endif

    #ifndef TIME
        long result = 0;
        #pragma omp parallel
        {
            #pragma omp single
            result = calculate_delanoy(problem_size, problem_size);
        }
        printf("delanoy number for given input: %ld\n",result);
    #endif
}