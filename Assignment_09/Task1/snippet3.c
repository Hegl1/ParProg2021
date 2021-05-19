#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARR_LEN 50

void init_array(float* array, int len, float number);
void print_array(float* array, int len);
void original_snippet(float* x, float* y, int len);
void parallel_snippet(float* x, float* y, int len);


int main(){

    float x[ARR_LEN];
    float y[ARR_LEN];
    init_array(x, ARR_LEN, 69);
    init_array(y, ARR_LEN, 42);
    original_snippet(x, y, ARR_LEN);
    print_array(y, ARR_LEN);


    init_array(x, ARR_LEN, 69);
    init_array(y, ARR_LEN, 42);
    parallel_snippet(x, y, ARR_LEN);
    print_array(y, ARR_LEN);


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

void original_snippet(float* x, float* y,  int len){
    double start_time = omp_get_wtime();
    int a = 3;
    int b = 4;


    for (int i=0; i < len; i++) {
        x[i] = y[i] * 2 + b*i;
    }

    for (int i=0; i < len; i++) {
        y[i] = x[i] + a/(i+1);
    }

    double end_time = omp_get_wtime();

    printf("time: %5.4f\n", end_time-start_time);

}

void parallel_snippet(float* x, float* y, int len){
    double start_time = omp_get_wtime();
    int a = 3;
    int b = 4;


    #pragma omp parallel
    {
        #pragma omp for
        for (int i=0; i < len; i++) {
        x[i] = y[i] * 2 + b*i;
        }

        #pragma omp for
        for (int i=0; i < len; i++) {
            y[i] = x[i] + a/(i+1);
        }
    }

    double end_time = omp_get_wtime();
    printf("time: %5.4f\n", end_time-start_time);
}


