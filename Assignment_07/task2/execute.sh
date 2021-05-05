#!/bin/bash

make times_no_vec_float > /dev/null

echo "*"
echo "OMP vectorized float variant"

for ((COUNTER=2048; COUNTER<=14336; COUNTER+=2048));
do
    echo "-"
    ./task2_float.out $COUNTER

done

make clean > /dev/null

make times_no_vec_double > /dev/null

echo "*"
echo "OMP vectorized double variant"

for ((COUNTER=2048; COUNTER<=14336; COUNTER+=2048));
do
    echo "-"
    ./task2_double.out $COUNTER

done

make clean > /dev/null

