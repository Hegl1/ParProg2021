#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define ARR_LEN 30

void init_array(float* array, int len, float number);
void print_array(float* array, int len);
void original_snippet(float* x, float* y, float* result, int len);
void parallel_snippet(float* x, float* y, int len);
void copy_arrray(float* a, float* b, int len);


int main(void){

    double* x = malloc(sizeof(double) * ARR_LEN);
    double* y = malloc(sizeof(double) * ARR_LEN);
    double* result = malloc(sizeof(double) * ARR_LEN);
    init_array(x, ARR_LEN, 69);
    init_array(y, ARR_LEN, 42);
    original_snippet(x, y, result, ARR_LEN);
    print_array(result, ARR_LEN);


    init_array(x, ARR_LEN, 69);
    init_array(y, ARR_LEN, 42);
    parallel_snippet(x, y, ARR_LEN);
    print_array(result, ARR_LEN);
}

void init_array(float* array, int len, float number){
    for (int i = 0; i<len; i++){
        array[i] = number;
    }
}

void print_array(float* array, int len){
    printf("[ ");
    for (int i = 0; i<len; i++){
        printf("%5.7f ", array[i]);
    }
    printf("]\n");
}

void copy_arrray(float* a, float* b, int len){
    for (int i = 0; i < len; i++){
        b[i] = a[i];
    }
}

void original_snippet(float* x, float* y, float* result, int len){
    double start_time = omp_get_wtime();
    double factor = 1;

    for (int i=0; i < ARR_LEN; i++) {
        x[i] = factor * y[i];
        factor = factor / 2;
    }

    double end_time = omp_get_wtime();

    printf("time: %5.7f\n", end_time-start_time);

    copy_arrray(x, result, len);
}

void parallel_snippet(float* x, float* y, int len){
    double start_time = omp_get_wtime();
    omp_set_num_threads(8);
    #pragma omp parallel
        #pragma omp for
        for (int i=0; i < len; i++) {
            x[i] = 1 / pow(2, i) * y[i];
        }
    double end_time = omp_get_wtime();
    printf("time: %5.4f\n", end_time-start_time);
}


