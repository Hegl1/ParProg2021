#!/bin/bash

make times_vec > /dev/null

echo "*"
echo "Speedup vectorized variant"

for ((COUNTER=2048; COUNTER<=14336; COUNTER+=2048));
do
    echo "-"
    ./task3.out $COUNTER

done

make clean > /dev/null

