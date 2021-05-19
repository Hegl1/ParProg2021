#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARR_LEN 50

void init_array(float* array, int len, float number);
void print_array(float* array, int len);
void original_snippet(float* x, float* y, float* result, int len);
void parallel_snippet(float* x, float* y, float* result, int len);
void copy_arrray(float* a, float* b, int len);


int main(){

    float x[ARR_LEN];
    float y[ARR_LEN];
    float result[ARR_LEN];
    init_array(x, ARR_LEN, 69);
    init_array(y, ARR_LEN, 42);
    original_snippet(x, y, result, ARR_LEN);
    print_array(result, ARR_LEN);


    init_array(x, ARR_LEN, 69);
    init_array(y, ARR_LEN, 42);
    parallel_snippet(x, y, result, ARR_LEN);
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
        printf("%5.2f ", array[i]);
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
    for (int i=0; i < len-1; i++) {
        x[i] = (y[i] + x[i+1]) / 7;
    }
    double end_time = omp_get_wtime();

    printf("time: %5.4f\n", end_time-start_time);

    copy_arrray(x, result, len);
}

void parallel_snippet(float* x, float* y, float* result, int len){
    double start_time = omp_get_wtime();
    #pragma omp parallel for
    for (int i=0; i < len-1; i++) {
        result[i] = (y[i] + x[i+1]) / 7;
    }
    double end_time = omp_get_wtime();
    printf("time: %5.4f\n", end_time-start_time);
}


