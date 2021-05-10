## Task 2

### Relevant Code

The base code stays the same as in task 1 but when we compile it, we leave out the `-ftree-vectorize` flag for gcc.

### Enable Vectorization

To achieve vectorization with OpenMP, we have to add some code:

```c
void calculate_array(float* a, float* b, float* c, int size){
    for(int run = 0; run < REPETITIONS; run++){
        #pragma omp simd aligned(a, b, c : 16)
        for(int i = 0; i<size; ++i){
            a[i] += b[i] * c[i];
        }
    }
}
```

The pragma with simd (single instruction multiple data) passes the following operation on vector to vector-unit, so the following for-loop is vectorized with this statement. To this kind of pragma we could also add some tags like "collapse". But collapse wouldn't work in this case, because the for loops can't be merged together effectively. I used the pragme with the addition "aligned", to tell the compiler what variables are aligend and how. I chose 16 Bytes cause it is a multiple of 4 Bytes (float) and it worked out just fine.

### Results

![speedup_task2_float](task1/plots/speedup_task2_float.png)

| Input size | Reference | OMP vectorized float variant |
| ---------- | --------- | ---------------------------- |
| 2048       | 2.4803    | 0.6273                       |
| 4096       | 5.793     | 2.3432                       |
| 6144       | 8.4365    | 4.0784                       |
| 8192       | 11.3653   | 5.4405                       |
| 10240      | 14.6792   | 6.7916                       |
| 12288      | 17.1076   | 8.1644                       |
| 14336      | 19.6561   | 9.4978                       |

![speedup_task2_double](task1/plots/speedup_task2_double.png)

| Input size | DOUBLE REFERENCE | OMP vectorized double variant |
| ---------- | ---------------- | ----------------------------- |
| 2048       | 3.8162           | 2.3241                        |
| 4096       | 8.1139           | 5.4368                        |
| 6144       | 12.1735          | 8.1459                        |
| 8192       | 16.2351          | 10.8549                       |
| 10240      | 20.2895          | 13.5741                       |
| 12288      | 24.3465          | 16.3016                       |
| 14336      | 28.3404          | 19.0122                       |

### Obersvations

- For float values we achieve a speedup ~ 4 but for double variables it is only ~ 1,65:
  Probably double is bigger, so the CPU can't load that much double variables concurrent compared to float variables, which have half the size. CPUs which use the avx standard, which allows to load more double variables at the same time, better speedups are achievable.

### Perf

So the program with input parameter 2048, has 2048 \* 1e6 operations.

- perf stat -e r04C7 ./task2_double.out 2048, this command measures all successfully vectorized operations(executed on vector-unit) for double values.

output: 3,072,000,000 r04C7:u
so there are 3 billion operations on double variables that were packed on the vector unit (there are also other double variables in the program, e.g. for time measurement)

- perf stat -e r01C7 ./task2_float.out 2048, this command measures all successfully vectorized operations(executed on vector-unit) for float values.

output: 2,048,000,058 r01C7:u
so every operation on float variable is vectorized, cause float variables are only used for our measured computation(no other float variables occur) -> good vectorization -> good speedup (~4)

### Comparing to Task1

We get a much better speedup for float variabels compared to task1, so doing vectorization by yourself might be more work and has to be done correctly obviously, but will pay off, if it's well implemented.
