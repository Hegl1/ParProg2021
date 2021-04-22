#!/bin/bash

Make times > /dev/null

echo "*"
echo "Delannoy_par.c"

for i in {1..8}
do
    echo "-"
    ./delannoy_par.out 14 $i

done

Make clean > /dev/null