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

# Use gcc 8.2.0 as the default gcc
module load gcc/8.2.0

# Set up any environment variables
export OMP_NUM_THREADS=1

make
printf "\nThreads: 1\n"
printf "\nThreads : 1 sequentiell\n"
export OMP_NUM_THREADS=1
./heat_stencil_2D.out 500
printf "\nThreads : 1 parallel\n"
export OMP_NUM_THREADS=1
./heat_stencil_2D_parallel.out 500

printf "\nThreads: 8\n"
export OMP_NUM_THREADS=8
printf "\nThreads : 8 sequentiell\n"
./heat_stencil_2D.out 500
printf "\nThreads : 8 parallel\n"
./heat_stencil_2D_parallel.out 500
make clean
