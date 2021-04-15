CFLAGS = -std=gnu11 -Wall -Wextra -lm -fopenmp -O3
CC = gcc

.PHONY: all
all: ex1

.PHONY: clean
clean:
	$(RM) ex1.out

ex1: ex1.c
	$(CC) $(CFLAGS) ex1.c -o ex1.out