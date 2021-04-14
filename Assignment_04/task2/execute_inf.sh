#!/bin/bash
i = 1
while : 
do
	echo "Iteration $i"
	./$1
	((i++))
done
