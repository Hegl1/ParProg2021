```
[cb761027@login.lcc2 Assignment2]$ perf stat -e L1-dcache-loads,L1-dcache-loads-misses ./a2b

 Performance counter stats for './a2b':

           8455097      L1-dcache-loads:u
             40946      L1-dcache-loads-misses:u  #    0.48% of all L1-dcache hits

       0.011510387 seconds time elapsed

       0.006928000 seconds user
       0.002969000 seconds sys
```