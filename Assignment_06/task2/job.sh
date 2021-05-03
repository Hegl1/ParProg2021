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
printf "\n##############SEQUENTIELL####################\n"
printf "\nN = 8:\n"
export OMP_NUM_THREADS=1
./queens_problem.out 8
printf "\nN = 10:\n"
./queens_problem.out 10
printf "\nN = 12:\n"
./queens_problem.out 12

printf "\n##############PARALLEL####################\n"

printf "\nThreads: 1\n"
printf "\nThreads : 1 N=8 parallel\n"
./queens_problem_parallel.out 8

printf "\nThreads : 1 N=10 parallel\n"
./queens_problem_parallel.out 10

printf "\nThreads : 1 N=12 parallel\n"
./queens_problem_parallel.out 12

printf "\nThreads: 2\n"
export OMP_NUM_THREADS=2
printf "\nThreads : 2 N=8 parallel\n"
./queens_problem_parallel.out 8

printf "\nThreads : 2 N=10 parallel\n"
./queens_problem_parallel.out 10

printf "\nThreads : 2 N=12 parallel\n"
./queens_problem_parallel.out 12

printf "\nThreads: 4\n"
export OMP_NUM_THREADS=4
printf "\nThreads : 4 N=8 parallel\n"
./queens_problem_parallel.out 8

printf "\nThreads : 4 N=10 parallel\n"
./queens_problem_parallel.out 10

printf "\nThreads : 4 N=12 parallel\n"
./queens_problem_parallel.out 12

printf "\nThreads: 8\n"
export OMP_NUM_THREADS=8
printf "\nThreads : 8 N=8 parallel\n"
./queens_problem_parallel.out 8

printf "\nThreads : 8 N=10 parallel\n"
./queens_problem_parallel.out 10

printf "\nThreads : 8 N=12 parallel\n"
./queens_problem_parallel.out 12

make clean