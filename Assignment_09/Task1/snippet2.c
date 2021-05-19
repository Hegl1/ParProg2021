#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARR_LEN 50

void init_array(float* array, int len, float number);
void print_array(float* array, int len);
void original_snippet(float* x, float* y, float* z, int len);
void parallel_snippet(float* x, float* y, float* z, int len);


int main(){

    float x[ARR_LEN];
    float y[ARR_LEN];
    float z[ARR_LEN];
    init_array(x, ARR_LEN, 69);
    init_array(y, ARR_LEN, 42);
    original_snippet(x, y, z, ARR_LEN);
    print_array(z, ARR_LEN);


    init_array(x, ARR_LEN, 69);
    init_array(y, ARR_LEN, 42);
    parallel_snippet(x, y, z, ARR_LEN);
    print_array(z, ARR_LEN);


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

void original_snippet(float* x, float* y, float* z, int len){
    float a;
    double start_time = omp_get_wtime();
    for (int i=0; i < len; i++) {
        a = (x[i] + y[i]) / (i+1);
        z[i] = a;
    }
    double end_time = omp_get_wtime();
    printf("time: %5.4f\n", end_time-start_time);

}

void parallel_snippet(float* x, float* y, float* z, int len){
    float a;
    double start_time = omp_get_wtime();
    #pragma omp parallel for private(a)
    for (int i=0; i < len; i++) {
        a = (x[i] + y[i]) / (i+1);
        z[i] = a;
    }
    double end_time = omp_get_wtime();
    printf("time: %5.4f\n", end_time-start_time);
}


