FLAGS = -std=gnu11 -Wall -Wextra -fopenmp -O1
TIMEFLAGS = -std=gnu11 -fopenmp -O1 -D TIMES
VEC_FLAGS = $(FLAGS) -ftree-vectorize 
VEC_TIMEFLAGS = $(TIMEFLAGS) -ftree-vectorize -msse4.1

CC = gcc


.PHONY: all_vec all_no_vec times_no_vec times_vec clean

all_no_vec: no_vec

times_no_vec: t_no_vec

all_vec: vec

times_vec: t_vec

times: exc_prefix_seq_time exc_prefix_par_time

clean:
	$(RM) task1.out

no_vec: task1.c
	$(CC) $(FLAGS) task1.c -o task1.out

vec: task1.c
	$(CC) $(VEC_FLAGS) task1.c -o task1.out

t_no_vec: task1.c
	$(CC) $(TIMEFLAGS) task1.c -o task1.out

t_vec: task1.c
	$(CC) $(VEC_TIMEFLAGS) task1.c -o task1.out

