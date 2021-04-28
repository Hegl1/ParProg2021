#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void print_array(int32_t* array, int size);
void initialize_array(int32_t* array, int size);
void calculate_prefix_sum(int32_t* a, int32_t* b, int size, int number_of_threads);
int32_t calculate_partial_prefix_sum(int32_t* a, int32_t* b, int start_index, int end_inedex);
void apply_patch(int32_t* array, int start, int end, int32_t patch);


int main(int argc, char** argv){
    int problem_size;
    int number_of_threads;
    if(argc < 3){
        printf("usage: ./exc_prefix_par.out <problem size> <number_of_threads>\n");
        return EXIT_FAILURE;
    } else {
        problem_size = atol(argv[1]);
        number_of_threads = atol(argv[2]);
        omp_set_num_threads(number_of_threads);
    }

    double start_time = omp_get_wtime();
    int32_t a[problem_size];
    int32_t b[problem_size];
    initialize_array(a, problem_size);
    calculate_prefix_sum(a, b, problem_size, number_of_threads);
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

void calculate_prefix_sum(int32_t* a, int32_t* b, int size, int number_of_threads){
    int sub_prob_size = size/number_of_threads;
    int32_t patches[number_of_threads];
    #pragma omp parallel
    {
    #pragma omp for schedule(static)
        for (int i = 0; i < number_of_threads; i++){
            int start = i * sub_prob_size;
            int end = i == number_of_threads-1 ? size : start + sub_prob_size;
            patches[i] = calculate_partial_prefix_sum(a, b, start, end);
        }

    #pragma omp for schedule(static)
        for (int i = 1; i < number_of_threads; i++){
            int start = i * sub_prob_size;
            apply_patch(b, start, size, patches[i-1]);
        }

    }
}

int32_t calculate_partial_prefix_sum(int32_t* a, int32_t* b, int start_index, int end_inedex){
    int sum = 0;
    for (int i = start_index; i < end_inedex; i++){
        sum+=a[i];
        b[i]=sum;
    }
    return sum;
}

void apply_patch(int32_t* array, int start, int end, int32_t patch){
    for (int i = start; i <end; i++){
        array[i]+=patch;
    }
}