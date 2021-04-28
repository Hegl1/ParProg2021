CFLAGS = -std=gnu11 -Wall -Wextra -fopenmp -O3
TIMEFLAGS = -std=gnu11 -fopenmp -O3 -D TIME
CC = gcc-10

.PHONY: all
all: exc_prefix_seq exc_prefix_par

.PHONY: times
times: exc_prefix_seq_time exc_prefix_par_time

.PHONY: clean
clean:
	$(RM) exc_prefix_seq.out exc_prefix_par.out

exc_prefix_seq: exclusive_prefix_seq.c
	$(CC) $(CFLAGS) exclusive_prefix_seq.c -o exc_prefix_seq.out

exc_prefix_seq_time: exclusive_prefix_seq.c
	$(CC) $(TIMEFLAGS) exclusive_prefix_seq.c -o exc_prefix_seq.out

exc_prefix_par: exclusive_prefix_par.c
	$(CC) $(CFLAGS) exclusive_prefix_par.c -o exc_prefix_par.out

exc_prefix_par_time: exclusive_prefix_par.c
	$(CC) $(TIMEFLAGS) exclusive_prefix_par.c -o exc_prefix_par.out