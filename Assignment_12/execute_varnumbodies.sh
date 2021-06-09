#!/bin/bash

make times > /dev/null

echo "*"
echo "Parallelized Version"

for ((COUNTER=500; COUNTER<=5000; COUNTER+=500));
do
    echo "-"
    OMP_NUM_THREADS=8 ./n_bodies.out $COUNTER 100

done

make clean > /dev/null