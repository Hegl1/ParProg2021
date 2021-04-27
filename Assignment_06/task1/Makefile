CFLAGS = -std=gnu11 -Wall -Wextra -fopenmp -O3
TIMEFLAGS = -std=gnu11 -fopenmp -O3 -D TIME
CC = gcc-10

.PHONY: all
all: exc_prefix_seq

.PHONY: times
times: exc_prefix_seq_time

.PHONY: clean
clean:
	$(RM) exc_prefix_seq.out

exc_prefix_seq: exclusive_prefix_seq.c
	$(CC) $(CFLAGS) exclusive_prefix_seq.c -o exc_prefix_seq.out

exc_prefix_seq_time: exclusive_prefix_seq.c
	$(CC) $(TIMEFLAGS) exclusive_prefix_seq.c -o exc_prefix_seq.out