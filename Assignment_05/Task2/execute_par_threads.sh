#!/bin/bash

make > /dev/null

echo "*"
echo "heat_stencil_2D_parallel.c"

for i in {1..8}
do
    echo "-"
    OMP_NUM_THREADS=$i ./heat_stencil_2D_parallel.out 500

done

make clean > /dev/null