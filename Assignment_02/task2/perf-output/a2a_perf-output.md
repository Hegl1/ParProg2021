```
[cb761027@login.lcc2 Assignment2]$ perf stat -e L1-dcache-loads,L1-dcache-loads-misses ./a2a

 Performance counter stats for './a2a':

           7875693      L1-dcache-loads:u
             10483      L1-dcache-loads-misses:u  #    0.13% of all L1-dcache hits

       0.008103076 seconds time elapsed

       0.004392000 seconds user
       0.003294000 seconds sys
```