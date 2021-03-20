#!/bin/bash
for i in {1..8}
do
    ./monte_carlo_par 500000000 $i
done
echo "-"
for i in {1..8}
do
    ./monte_carlo_ser 500000000
done