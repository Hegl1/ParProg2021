#!/bin/bash

make > /dev/null

echo "*"
echo "Reference"

for ((COUNTER=1; COUNTER<=8; COUNTER+=1));
do
    echo "-"
    OMP_NUM_THREADS=$COUNTER /usr/bin/time ./real

done

echo "*"
echo "Reference"

for ((COUNTER=1; COUNTER<=8; COUNTER+=1));
do
    echo "-"
    OMP_NUM_THREADS=1 /usr/bin/time ./real

done

make clean > /dev/null

