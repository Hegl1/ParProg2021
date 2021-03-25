#!/bin/bash
for i in {1..8}
do
    ./monte_carlo_threads.out 500000000 $i
done
echo "-"
for i in {1..8}
do
    ./monte_carlo_reduction.out 500000000 $i
done
echo "-"
for i in {1..8}
do
    ./monte_carlo_atomic.out 500000000 $i
done
echo "-"
for i in {1..8}
do
    ./monte_carlo_critical.out 500000000 $i
done
