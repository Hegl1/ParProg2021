---
author: Tobias Hosp, Marcel Alexander Huber and Thomas Klotz
title: Assignment 9
---

# Assignment 9

## Task 1

### Snippet 1

```C
	for (int i=0; i < n-1; i++) {
1			tmp = (y[i] + x[i+1]) / 7;
2    	x[i] = tmp;
	}
```

Since we read x[i+1] in line one and write the result into x[i] in line two, there is an antidependence across the loop iteration bettwen line one and line 2.
($1 \delta^{-1} 2$ with distance (-1) and direction (>)) .

### Parallel Snippet 1

In order to parallelize snipped one, we introduced a fresh variable.

```C
#pragma omp parallel for
for (int i = 0; i<len-1; i++){
  a2[i] = (y[i] + x[i+1])/7
}
```

## Snippet 2

```C
	for (int i=0; i<n; i++){
1    a = (x[i] + y[i]) / (i+1);
2    z[i] = a;
  }
	f = sqrt(a + k);
```

In this snipped, there is obvously a dependence between 1 and 2, but there are **no** dependences across loop iterations. 

### Parallel Snippet 2

To parallelize this snipped, the loop did not need any changes. The only thing to change was the parameter a of the sqrt function (since the value of a is undefined at the end of the loop).

```c
#pragma omp parallel private(a)
for(int i = 0; i<n; i++){
	a = (x[i] + y[i])/(i+1);
  z[i] = a;
}
f = sqrt(z[n-1] + k);
```

## Snippet 3

```C
1	for (int i=0; i < n; i++) {
   	x[i] = y[i] * 2 + b * i;
	}

2	for (int i=0; i < n; i++) {
   	y[i] = x[i]  + a / (i+1);
	}
```

There is no data dependence per for loop. Therefore, loop 2 depends on loop1. This can be parallelized very easy though.

### Parallel snippet 3

```C
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
```



