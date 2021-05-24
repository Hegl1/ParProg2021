FLAGS = -std=gnu11 -Wall -Wextra -fopenmp -pedantic
CC = gcc

.PHONY: all clean snippet

all: snippet

clean:
	$(RM) snippet.out

snippet: snippet.c
	$(CC) $(FLAGS) snippet.c -o snippet.out
