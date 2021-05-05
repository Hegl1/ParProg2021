#!/bin/bash

make times > /dev/null

echo "*"
echo "title"

for ((COUNTER=2048; COUNTER<=14336; COUNTER+=2048));
do
    echo "-"
    ./task3.out $COUNTER

done

make clean > /dev/null

