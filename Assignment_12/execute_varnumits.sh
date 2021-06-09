#!/bin/bash

make times > /dev/null

echo "*"
echo "Parallelized Version"

for ((COUNTER=200; COUNTER<=2000; COUNTER+=200));
do
    echo "-"
    OMP_NUM_THREADS=8 ./n_bodies.out 1000 $COUNTER

done

make clean > /dev/null