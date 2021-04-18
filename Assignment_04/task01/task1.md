## Task1

### Writing the basic program

To achieve a execution time of at least 2 seconds, by incrementing an integer value, i used a volatile integer variable. Volatile variables can't be cached, so they're always fetched from the memory -> much longer execution time.
With 1900000000 iterations on my local machine respectively 1000000000 on lcc2 with 1 thread and optimization flag -O3, the program needs about 2 seconds to execute completely. I think without volatile, just with a normal int, it is almost impossible to get an execution time that high.

### OpenMP 4.0 Affinity

The developer has the opportunity to decide on how many PLACES(hyperthreads, cores, sockets,...) the threads are executed. Places can be set with the Environment variables OMP_PLACES and the num threads variable could then look like this for 8 places: OMP_NUM_THREADS=4,4 (4,4 means nested: first 4 threds are started and then again 4 -> 16 threads; relevant for example below)

PLACES can also be defined by the developer:
OMP_PLACES="{0,1},{2,3},{4,5},{6,7},{8,9},{10,11},{12,13},{14,15}" (example)

#### Predifined places:

- cores: physical cores
- threads: hyperthreads
- sockets: processor package

#### Affinity policies:

- spread: spread threads evenly among places
- close: place threads near master thread
- master: collocate thread with master thread

#### Example:

![OpenMP4_0_Example](OpenMP4_0_Example.PNG)

#### Measurements:

#### Reference Value:

4 Threads basic program, just with -O3: 2.45598

4 Threads with omp parallel for optimization:

```c
#pragma omp parallel for
	for (long i = 0; i < n; i++) {
		inc++;
	}
```

Measure: 0.78777 seconds

4 Threads with omp proc_bind(spread):

```c
#pragma omp parallel proc_bind(spread)
	#pragma omp for
		for (long i = 0; i < n; i++) {
			inc++;
		}
```

Measure:

| number_of_threads | PLACES=cores(4) | PLACES=threads(4) | PLACES=sockets(4) |
| ----------------- | --------------- | ----------------- | ----------------- |
| 2,2               | 0.75619         | 0.75606           | 0.78641           |

4 Threads with just omp proc_bind(close):

```c
#pragma omp parallel proc_bind(close)
	#pragma omp for
		for (long i = 0; i < n; i++) {
			inc++;
		}
```

Measure:

| number_of_threads | PLACES=cores(4) | PLACES=threads(4) | PLACES=sockets(4) |
| ----------------- | --------------- | ----------------- | ----------------- |
| 4                 | 0.75309         | 0.75300           | 0.78591           |

4 Threads with just omp proc_bind(master):

```c
#pragma omp parallel proc_bind(master)
	#pragma omp for
		for (long i = 0; i < n; i++) {
			inc++;
		}
```

Measure:

| number_of_threads | PLACES=cores(4) | PLACES=threads(4) | PLACES=sockets(4) |
| ----------------- | --------------- | ----------------- | ----------------- |
| 4                 | 2.46937         | 2.47554           | 0.73690           |

-> Master doesn't do anything for cores and threads but works for sockets

Using 2,2 threads omp parallel for and proc_bind(spread) nested with proc_bind(close) before it:

```c
#pragma omp parallel proc_bind(spread)
	#pragma omp parallel proc_bin(close)
    	#pragma omp for
			for (long i = 0; i < n; i++) {
		    	inc++;
			}
```

Measure:

| number_of_threads | PLACES=cores(4) | PLACES=threads(4) | PLACES=sockets(4) |
| ----------------- | --------------- | ----------------- | ----------------- |
| 4                 | 0.00014         | 0.00010           | 0.00018           |

Using 2,2 threads omp parallel for and proc_bind(spread) nested with proc_bind(master) before it:

```c
#pragma omp parallel proc_bind(spread)
        #pragma omp parallel proc_bind(master)
            #pragma omp for
		        for (long i = 0; i < n; i++) {
			        inc++;
		        }
```

Measure:

| number_of_threads | PLACES=cores(4) | PLACES=threads(4) | PLACES=sockets(4) |
| ----------------- | --------------- | ----------------- | ----------------- |
| 4                 | 0.00014         | 0.00010           | 0.00020           |

### Conclusion:

So splitting the threads with proc_bind(spread) and proc_bin(close) looks like a really good option to optimize the code, because it went from about 2.4 seconds to 0.00010 seconds.

The version where only proc_bind(master) is used, is in this case not helpful, because it operates like it runs not optimized. proc-bind(master) and also close are good for caching-cases and so on, but i "disabled" it with the volatile int.

### Resources:

- https://www.lrz.de/services/compute/courses/x_lecturenotes/mic_workshop_2017/Michael-Klemm-tutorial.pdf
- https://www.openmp.org//wp-content/uploads/openmp-examples-4.0.2.pdf
