CFLAGS = -Wall -Wextra -Werror -std=gnu11 -fopenmp -O3
CC = gcc

.PHONY: all
all: snippet1 snippet2 snippet3

.PHONY: clean

clean:
	$(RM) snippet1 snippet2 snippet3

snippet1: snippet1.c -lm

snippet2: snippet2.c -lm

snippet3: snippet3.c -lm