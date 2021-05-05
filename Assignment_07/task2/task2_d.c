#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

#define REPETITIONS 1e6

void init_array(double*, int, double);
void calculate_array(double*, double*, double*, int);
void print_array(double*, int);
void print_output();

int main(int argc, char** argv){

    if(argc < 2){
        printf("usage: task1.out <vector_size>\n");
        return EXIT_FAILURE;
    }
    
    const int size = strtol(argv[1], NULL, 0);

    double a[size], b[size], c[size];
    init_array(a, size, 0);
    init_array(b, size, 1);
    init_array(c, size, 2);

    double start_time = omp_get_wtime();
    calculate_array(a, b, c, size);
    double end_time = omp_get_wtime();
    print_output(start_time, end_time, a, size);


    return EXIT_SUCCESS;
}

void init_array(double* arr, int size, double init_num){
    for(int i = 0; i<size; ++i){
        arr[i] = init_num;
    }
}

void calculate_array(double* a, double* b, double* c, int size){
    for(int run = 0; run < REPETITIONS; run++){
        for(int i = 0; i<size; ++i){
            a[i] += b[i] * c[i];
        }
    }
}

void print_array(double* arr, int size){
    printf("[ ");
    for(int i = 0; i<size; i++){
        printf("%.2f ", arr[i]);
    }
    printf("]\n");
}

void print_output(double start_time, double end_time, double* arr, int size){
    #ifdef TIMES
        printf("time: %.4f\n", end_time - start_time);
    #else
        printf("time: %.4f ", end_time - start_time);
        print_array(arr, size);
    #endif 
}