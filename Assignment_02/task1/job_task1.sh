#$ -o job.dat

# Join the error stream to the output stream.
#$ -j yes

# Parallel environment for using OpenMP, allocates 8 cores on a single node
#$ -pe openmp 8

# Use gcc 8.2.0 as the default gcc
module load gcc/8.2.0

# Set up any environment variables
export OMP_NUM_THREADS=1

echo "MANDELBROT"

# ./path/to/application <command> <line> <arguments>
make
./mandelbrot
make clean