CFLAGS = -std=gnu11 -Wall -Wextra -lm -fopenmp
CC = gcc

.PHONY: all
all: heat_stencil_2D

.PHONY: clean
clean:
	$(RM) heat_stencil_2D.out

heat_stencil_2D: heat_stencil_2D.c
	$(CC) $(CFLAGS) heat_stencil_2D.c -o heat_stencil_2D.out