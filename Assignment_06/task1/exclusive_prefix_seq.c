#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void print_array(int32_t* array, int size);
void initialize_array(int32_t* array, int size);
void calculate_prefix_sum(int32_t* a, int32_t* b, int size);


int main(int argc, char** argv){
    int problem_size;
    if(argc < 2){
        printf("usage: ./exc_prefix_seq.out <problem size>\n");
        return EXIT_FAILURE;
    } else {
        problem_size = atol(argv[1]);
    }

    double start_time = omp_get_wtime();
    int32_t a[problem_size];
    int32_t b[problem_size];
    initialize_array(a, problem_size);
    calculate_prefix_sum(a, b, problem_size);
    double end_time = omp_get_wtime();
    #ifdef TIME
    printf("time: %2.9f\n", end_time-start_time);
    #else
    printf("b[%d] = %d, time: %2.9f\n", problem_size-1, b[problem_size-1], end_time-start_time);
    return EXIT_SUCCESS;
    #endif
}

void print_array(int32_t* array, int size){
    printf("[ ");
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void initialize_array(int32_t* array, int size){
    for (int i = 0; i<size; i++){
        array[i] = 1;
    }
}

void calculate_prefix_sum(int32_t* a, int32_t* b, int size){
    b[0] = 0;
    for(int i = 1; i<size; i++){
        b[i] = b[i-1]+a[i-1];
    }
}