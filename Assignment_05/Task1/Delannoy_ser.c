#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv){

    int matrix_size = 0;

    if(argc < 2){
        printf("usage: ./delannoy_ser.out <gridsize>\n");
        return EXIT_FAILURE;
    } else {
        matrix_size = atol(argv[1]);
    }

    long delannoy_array[matrix_size+1][matrix_size+1];

    #ifdef TIME
    double start_time = omp_get_wtime();
    #endif

    for (int i = 0; i <= matrix_size; i++){
        delannoy_array[0][i] = 1;
        delannoy_array[i][0] = 1;
    }


    for (int i = 1; i<=matrix_size; i++){
        for (int j = 1; j<=matrix_size; j++){
            delannoy_array[i][j] = delannoy_array[i-1][j] + delannoy_array[i][j-1] + delannoy_array[i-1][j-1];
        }
    }
    #ifdef TIME
    double end_time = omp_get_wtime();
    printf("time: %2.9f \n",end_time-start_time);
    #endif

    #ifndef TIME
    printf("delanoy number for given input: %ld\n", delannoy_array[matrix_size][matrix_size]);
    #endif
    return EXIT_SUCCESS;
}
