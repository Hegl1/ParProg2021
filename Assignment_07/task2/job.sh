#!/bin/bash

# Executes job in the queue "lva.q" unless you have special requirements.
#$ -q lva.q

# Changes to the current working directory before performing any further action
#$ -cwd

# Name of your job. Unless you use the -o and -e options, output will
# go to a unique file name.ojob_id for each job.
#$ -N job

# Redirect output stream to this file.
#$ -o job.dat

# Join the error stream to the output stream.
#$ -j yes

# Parallel environment for using OpenMP, allocates 8 cores on a single node
#$ -pe openmp 8

# Use gcc 10.3.0 as the default gcc
module load gcc/10.3.0

# Set up any environment variables
export OMP_NUM_THREADS=1

make times_no_vec
printf "\nREFERENCE\n"
./task2.out 2048
make times_no_vec_float
printf "\nFLOAT\n"
./task2_float.out 2048
make times_no_vec_double
printf "\nDOUBLE\n"
./task2_double.out 2048
make clean