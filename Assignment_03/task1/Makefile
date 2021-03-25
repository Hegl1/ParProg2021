CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp
CC = gcc

.PHONY: all
all: monte_carlo_atomic monte_carlo_critical monte_carlo_reduction

.PHONY: clean
clean:
	$(RM) monte_carlo_atomic.out monte_carlo_critical.out monte_carlo_reduction.out

monte_carlo_atomic: monte_carlo_pi_openmp_atomic.c
	$(CC) $(CFLAGS) monte_carlo_pi_openmp_atomic.c -o monte_carlo_atomic.out

monte_carlo_critical: monte_carlo_pi_openmp_critical.c
	$(CC) $(CFLAGS) monte_carlo_pi_openmp_critical.c -o monte_carlo_critical.out

monte_carlo_reduction: monte_carlo_pi_openmp_reduction.c
	$(CC) $(CFLAGS) monte_carlo_pi_openmp_reduction.c -o monte_carlo_reduction.out

monte_carlo_threads: monte_carlo_threads.c
	$(CC) $(CFLAGS) monte_carlo_threads.c -o monte_carlo_threads.out