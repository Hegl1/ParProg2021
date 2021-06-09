#!/bin/bash

make times > /dev/null

echo "*"
echo "Parallelized Version"

for ((COUNTER=1; COUNTER<=8; COUNTER+=1));
do
    echo "-"
    OMP_NUM_THREADS=$COUNTER ./n_bodies.out 5000 100

done

echo "*"
echo "Reference"

for ((COUNTER=1; COUNTER<=8; COUNTER+=1));
do
    echo "-"
    OMP_NUM_THREADS=1 ./n_bodies.out 5000 100

done

make clean > /dev/null