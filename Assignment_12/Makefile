CC = gcc-10
CFLAGS = -Wall -Werror -pedantic -O3 -fopenmp -lm

.PHONY: all
all: n_body.c simulation.c
	$(CC) $(CFLAGS) n_body.c simulation.c -o n_bodies.out 
