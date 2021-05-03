#!/bin/bash

make > /dev/null

echo "*"
echo "Parallel version, input = 8"

for i in {1..8}
do
    echo "-"
    OMP_NUM_THREADS=$i ./queens_problem_parallel.out 8

done

echo "*"
echo "Parallel version, input = 10"

for i in {1..8}
do
    echo "-"
    OMP_NUM_THREADS=$i ./queens_problem_parallel.out 10

done

echo "*"
echo "Parallel version, input = 12"

for i in {1..8}
do
    echo "-"
    OMP_NUM_THREADS=$i ./queens_problem_parallel.out 12

done

make clean > /dev/null