#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

#define ARR_LEN 100000000

void init_array(double* array, int len);
void print_array(double* array, int len);
void original_snippet(double* x, double* y, double* result, int len);
void parallel_snippet(double* x, double* y, int len);
void copy_arrray(double* a, double* b, int len);


int main(void){

    double* x = malloc(sizeof(double) * ARR_LEN);
    double* y = malloc(sizeof(double) * ARR_LEN);
    double* result = malloc(sizeof(double) * ARR_LEN);
    init_array(x, ARR_LEN);
    init_array(y, ARR_LEN);
    original_snippet(x, y, result, ARR_LEN);
    //print_array(result, ARR_LEN);


    init_array(x, ARR_LEN);
    init_array(y, ARR_LEN);
    parallel_snippet(x, y, ARR_LEN);
    //print_array(result, ARR_LEN);
}

void init_array(double* array, int len){
    unsigned seed = time(NULL);
    for (int i = 0; i<len; i++){
        array[i] = rand_r(&seed);
    }
}

void print_array(double* array, int len){
    printf("[ ");
    for (int i = 0; i<len; i++){
        printf("%5.7f ", array[i]);
    }
    printf("]\n");
}

void copy_arrray(double* a, double* b, int len){
    for (int i = 0; i < len; i++){
        b[i] = a[i];
    }
}

void original_snippet(double* x, double* y, double* result, int len){
    double start_time = omp_get_wtime();
    
    x[0] = x[0] + 5 * y[0];
    for (int i = 1; i < len; i++) {
        x[i] = x[i] + 5 * y[i];

        if ( 0 ) {
            x[i-1] = 2 * x[i-1];
        }
    }


    double end_time = omp_get_wtime();

    printf("time: %5.7f\n", end_time-start_time);

    copy_arrray(x, result, len);
}

void parallel_snippet(double* x, double* y, int len){
    double start_time = omp_get_wtime();
    omp_set_num_threads(8);
    x[0] = x[0] + 5 * y[0];
    
    #pragma omp parallel
    if ( 0 ) {
        #pragma omp for
        for (int i = 1; i < len; i++) {
            x[i] = x[i] + 5 * y[i];
        }

        #pragma omp for
        for (int i = 1; i < len; i++) {
            x[i-1] = 2 * x[i-1];
        }
    }else{
        #pragma omp for
        for (int i = 1; i < len; i++) {
            x[i] = x[i] + 5 * y[i];
        }
    }
    double end_time = omp_get_wtime();
    printf("time: %5.4f\n", end_time-start_time);
}


