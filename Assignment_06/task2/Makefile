CFLAGS = -std=gnu11 -Wall -Wextra -lm -fopenmp -O3
CC = gcc

.PHONY: all
all: queens_problem queens_problem_parallel

.PHONY: clean
clean:
	$(RM) queens_problem.out queens_problem_parallel.out

queens_problem: queens_problem.c
	$(CC) $(CFLAGS) queens_problem.c -o queens_problem.out

queens_problem_parallel: queens_problem_parallel.c
	$(CC) $(CFLAGS) queens_problem_parallel.c -o queens_problem_parallel.out