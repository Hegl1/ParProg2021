# Assignment 7
by Tobias Hosp, Marcel Huber and Thomas Klotz

## Task 1

### Relevant Code

```c
void calculate_array(float* a, float* b, float* c, int size){
    for(int run=0; run<REPETITIONS; ++run){
        for(int i = 0; i<size; ++i){
            a[i] += b[i] * c[i];
        }
    }
}
```

Compiled with: 

```makefile
gcc -std=gnu11 -fopenmp -O1 -D TIMES -ftree-vectorize -msse4.1
```

### Enable Vectorization

To enable vectorization, the compiler flag ```-ftree-vectorize ``` was added to the usual gcc call.

### Results

![speedup_task1](task1/plots/speedup_task1.png)

| Input size | Compiled without vectorization | Compiled with vectorization |
| ---- | ---- | ---- |
| 2048 | 2.4803 | 1.725 |
| 4096 | 5.793 | 4.6677 |
| 6144 | 8.4365 | 7.4088 |
| 8192 | 11.3653 | 9.8276 |
| 10240 | 14.6792 | 12.2802 |
| 12288 | 17.1076 | 14.7419 |
| 14336 | 19.6561 | 17.2051 |

### Obersvations

- The result stays correct, independent of whether the code is compiled with vectorization or without.
- Enabling vectorization results in a speedup of ~1.44, decreasing with bigger input sizes to ~1.2

### Perf

Results for the perf measured events with an input size of 2048:

| Event | Value |
| --- | --- |
| SIMD_INST_RETIRED.PACKED_SINGLE | 1,024,001,590 |
| SIMD_INST_RETIRED.SCALAR_SINGLE | 2 |
| SIMD_INST_RETIRED.PACKED_DOUBLE | 0 |
| SIMD_INST_RETIRED.SCALAR_DOUBLE | 4,097,000,054 |
| SIMD_INST_RETIRED.VECTOR | 3,584,000,126 |
| SIMD_INST_RETIRED.ALL | 5,121,001,732 |

The relevant information is SIMD_INST_RETIRED.PACKED_SINGLE, since this event describes, how many operations are vectorized operations for single percision floating point numbers (floats). Since this number is roughly half of the iterations in the compute loop, we would expect a speedup of ~2.
At this point we do not know why we do not get a speedup of 2, nor do we know why there is such a high count of scalar double, although there are nearly no doubles used in the code.


### Useful resources

[Register sizes of different SIMD standards](https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookWritingAutovectorizableCode)

[Stackoverflow for vectorization flag](https://stackoverflow.com/questions/51232100/gcc-auto-vectorization)

[Instructions to enable specific SIMD instructions in gcc](https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html)

