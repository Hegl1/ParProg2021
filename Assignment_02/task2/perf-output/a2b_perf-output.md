```
[cb761027@login.lcc2 Assignment2]$ perf stat -e L1-dcache-loads,L1-dcache-loads-misses ./a2b
 
 Performance counter stats for './a2b':

           8468287      L1-dcache-loads:u
            116301      L1-dcache-loads-misses:u  #    1.37% of all L1-dcache hits

       0.009955886 seconds time elapsed

       0.006593000 seconds user
       0.003296000 seconds sys

```