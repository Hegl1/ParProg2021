CC = gcc
CFLAGS = -Wall -Werror -pedantic -O3 -fopenmp -lm

.PHONY: all clean times

all: n_body.c simulation.c
	$(CC) $(CFLAGS) n_body.c simulation.c -o n_bodies.out 

times: n_body.c simulation.c
	$(CC) $(CFLAGS) -D TIME_MES n_body.c simulation.c -o n_bodies.out 

clean: 
	$(RM) n_bodies.out simulation.out