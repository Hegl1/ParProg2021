---
author: Tobias Hosp, Marcel Alexander Huber and Thomas Klotz
title: Assignment 8
---

# Assignment 8
by Tobias Hosp, Marcel Alexander Huber and Thomas Klotz

## Task 2

### Compilation

analysis.c has been compiled with gcc 8.2.0 and the following command:
```gcc -Wall -Werror -std=gnu11 -O2 -ftree-vectorize -fopt-info-vec-all analysis.c -o analysis.out```

### Findings

#### Can you find any information pointint to successful or unsuccessful vectorization? 

The compiler prints the result for each vectorization attempt it makes (so there is a section for every loop).
If a loop was vectorized successfull, the compiler outputs `NOTE: LOOP VECTORIZED` at the end of an output block.
If the vectorization was unsuccessfull, the compiler prints a message with the reason why the loop could not be vectorized, e.g.:

```
analysis.c:22:9: note: not vectorized: not suitable for gather load _5 = a[_4];
analysis.c:22:9: note: bad data references.
```

and 

```
analysis.c:27:9: note: not vectorized: loop contains function calls or data references that cannot be analyzed
```

#### What information about dependence analysis can you find in the output? 

The compiler marks which kind of anylysis is performed. For example, there are output lines like

```
analysis.c:18:9: note: === vect_analyze_data_ref_accesses ===
```

which indicate that the data access patterns in the loop are analyzed. It also performs dependency analysis (`analysis.c:18:9: note: === vect_analyze_data_ref_dependences ===`) and cycle analysis (`=== vect_analyze_scalar_cycles ===`).

#### Does the compiler perform any analysis beyond checking for dependencies and semantic correctness? 

The compiler analyses whether SLP can be performed. According to [this source](https://llvm.org/docs/Vectorizers.html#the-slp-vectorizer) SLP stands for "Superword-level parallelism, which means that similar independent instructions get merged into vector insturctions (`=== vect_analyze_slp ===`). 
It also seems like the compiler checks how data is alligned (`=== vect_analyze_data_refs_alignment ===`).



