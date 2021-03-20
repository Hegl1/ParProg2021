#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h> 
#include <omp.h>

int main(int argc, char** argv){

    long n = 0;

    if(argc < 2){
        printf("Usage: ./monte_carlo_ser.out <n>\n");
        return EXIT_FAILURE;
    } else{
        n = atol(argv[1]);
    }

    double start_time = omp_get_wtime();

    srand(time(NULL));
    long total_inside = 0;
    for(int i = 0; i < n; i++){
        float x = ((double) rand() / (RAND_MAX));
        float y = ((double) rand() / (RAND_MAX));
        if((x*x + y*y)<= 1){
            total_inside++;
        }
    }

    double end_time = omp_get_wtime();

    printf("sum: %f time: %2.6f \n", 4 * (float) total_inside / n, end_time-start_time);

    return EXIT_SUCCESS;
}
