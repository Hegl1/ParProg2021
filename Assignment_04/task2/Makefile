CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3
CC = gcc

.PHONY: all
all: flush_original flush_better

.PHONY: clean
clean:
	$(RM) flush_original.out better_flush.out

flush_original: flush.c
	$(CC) $(CFLAGS) flush.c -o flush_original.out

flush_better: better_flush.c
	$(CC) $(CFLAGS) better_flush.c -o better_flush.out