## Task 1

### Code snippet 1

```c
a[0] = 0;
#pragma omp parallel for
for (i=1; i<N; i++) {
    a[i] = 2.0*i*(i-1);
    b[i] = a[i] - a[i-1];
}
```

the for loop is splitted in equal sizes for every thread, so a[i-1] could be computed by another thread and the value of this cell might
not exist at this point. -> not a good solution
Because of this dependency to the cell before (a[i-1]), this code is not that easy to parallelize. Probably the easiest way to do it, is
to generate the values of array a seperately, cause it doesn't depend on anything else than i:

```c
a[0] = 0;
#pragma omp parallel for
for (i=1; i<N; i++) {
    a[i] = 2.0*i*(i-1);
}
#pragma omp for
for (i=1; i<N; i++) {
    b[i] = a[i] - a[i-1];
}
```

### Code snippet 2

```c
a[0] = 0;
#pragma omp parallel
{
    #pragma omp for nowait
    for (i=1; i<N; i++) {
        a[i] = 3.0*i*(i+1);
    }
    #pragma omp for
    for (i=1; i<N; i++) {
        b[i] = a[i] - a[i-1];
    }
}
```

This is actually almost the solution i gave for the first snippet, but with `nowait`. This causes kind of race conditions, because now
the values in array `a` could be already initialized when they needed, but for sure, because the threads don't wait till a is completely calculated.

So the solution for this snippet would be the same as for the first snippet.

### Code snippet 3

```c
#pragma omp parallel for
for (i=1; i<N; i++) {
    x = sqrt(b[i]) - 1;
    a[i] = x*x + 2*x + 1;
}
```

x and b are bot shared variables. So here we have race conditions for sure, because x is set from every thread in every iteration, so the values of a could differ every time the program is executed. So the solution for this snipped might be to change x to a local variable, if it is not needed outside of the for loop.

### Code snippet 4

```c
f = 2;
#pragma omp parallel for private(f,x)
for (i=1; i<N; i++) {
    x = f * b[i];
    a[i] = x - 7;
}
a[0] = x;
```

This is almost a good implementation, cause compared to the snippet before, f and x are private now, so there are local copies for every thread and the values won't differ for different executions anymore. Although it's unnecessary to copy `f` cause it is a constant. No dependencies on a cell before or anything like in the first two code snippets.

But the last line: `a[0] = x` this actually causes a race condition again, cause depending on which thread executes last, it's set to the x value of that thread. It is difficult to say how to fix this code, because i don't know what we actually want in a[0]. If we want it to be the last value and to be always the same value, we could set it to a[0] = a[N - 1]

### Code snippet 5

```c
sum = 0;
#pragma omp parallel for
for (i=1; i<N; i++) {
    sum = sum + b[i];
}
```

This code causes again race conditions, because sum is a shared variable and it highly affects the output of every thread/iteration. Luckily this is a good case for using reduction, so it will be easy to fix:

```c
sum = 0;
#pragma omp parallel for reduction (+:sum)
for (i=1; i<N; i++) {
    sum = sum + b[i];
}
```
