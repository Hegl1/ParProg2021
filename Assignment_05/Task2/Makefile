CFLAGS = -std=gnu11 -Wall -Wextra -lm -fopenmp -O3
CC = gcc

.PHONY: all
all: heat_stencil_2D heat_stencil_2D_parallel

.PHONY: clean
clean:
	$(RM) heat_stencil_2D.out heat_stencil_2D_parallel.out

heat_stencil_2D: heat_stencil_2D.c
	$(CC) $(CFLAGS) heat_stencil_2D.c -o heat_stencil_2D.out

heat_stencil_2D_parallel: heat_stencil_2D_parallel.c
	$(CC) $(CFLAGS) heat_stencil_2D_parallel.c -o heat_stencil_2D_parallel.out