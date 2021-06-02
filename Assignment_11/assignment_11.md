---
author: Tobias Hosp, Marcel Alexander Huber and Thomas Klotz
title: Assignment 11
---

# Assignment 11

## Task 1

### Snippet a
`c1` is of type `unsigned`
```C
unsigned c2 = 32 * c1;
```
If we assume that the multiplication takes longer then a bit shift, we can optimize this code as follows:

```C
unsigned c2 = c1 << 5;
```

If we look at the compiled assembly code, we see no difference between those two snippets when compiled with `-O3`. 

### Snippet b

`c1` is of type `unsigned`
```C
unsigned c2 = 15 * c1;
```
Assuming bit shifting + one subtraction are faster then a multiplication, one could do this: 

```c
unsigned c2 = (c1 << 4) - c1;
```

Once again the corresponding assembly codes are identical.

### Snippet c

`c1` is of type `unsigned`
```C
unsigned c2 = 96 * c1;
```
Assuming that 2 shift operations and one addition are still faster then a single multiplication, the following optimization could be helpful:

```c
unsigned c2 = (c1 << 5) + (c1 << 6);
```

The compiler **disagrees** with this optimization. The 'optimized' snippet gets replaced by the following code:

```assembly
c_solution:
        imul    esi, edi, 96
        xor     eax, eax
        mov     edi, OFFSET FLAT:.LC2
        jmp     printf
```

which basically performs a multiplication by 96, which means that the compiler thinks that the unoptimized version is faster then the optimized one.
Additionally, if we compile the unoptimized version, the compiler does the following: 

```assembly
c:
        lea     esi, [rdi+rdi*2]
        xor     eax, eax
        mov     edi, OFFSET FLAT:.LC2
        sal     esi, 5
        jmp     printf
```

Since we are not quite tallented with x86 assembly code, we cannot explain this snippet.

### Snippet d

`c1` is of type `unsigned`
```C
unsigned c2 = 0.125 * c1;
```
Since the multiplication of 0.125 is equivalent to the division by 8, we can optimize this snippet as follows:

```c
unsigned c2 = c1 >> 3;
```

The compiler translates this to the expected assembly code:

```assembly
d_solution:
        mov     esi, edi
        xor     eax, eax
        mov     edi, OFFSET FLAT:.LC4
        shr     esi, 3
        jmp     printf
```

But if we look at the compiled unoptimized version, the compiler thinks this magic looking code is faster then a normal multiplication:

```assembly
d:
        mov     edi, edi
        pxor    xmm0, xmm0
        xor     eax, eax
        cvtsi2sdq       xmm0, rdi
        mulsd   xmm0, QWORD PTR .LC3[rip]
        mov     edi, OFFSET FLAT:.LC4
        cvttsd2si       rsi, xmm0
        jmp     printf
```

### Snippet e

`a` is of type `unsigned *`

```C
unsigned sum_fifth = 0;
for (int i = 0; i < N / 5; ++i) {
    sum_fifth += a[5 * i];
}
```
If we want to get rid of the expensive multiplication inside the loop, we can simply transform the loop head like this:

```C
unsigned sum_fifth = 0;
for (int i = 0; i < N; i+=5) {
    sum_fifth += a[i];
}
```

The compiled versions of the unoptimized and optimized snippet look identical.

### Snippet f

`a` is of type `double *`
```C
for (int i = 0; i < N; ++i) {
    a[i] += i / 5.3;
}
```
### Snippet g
`c1` is of type `float`
```C
float c2 = -1 * c1;
```