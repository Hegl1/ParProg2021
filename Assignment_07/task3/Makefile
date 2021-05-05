FLAGS = -std=gnu11 -Wall -Wextra -fopenmp -O1
TIMEFLAGS = -std=gnu11 -fopenmp -O1 -D TIMES
VEC_FLAGS = $(FLAGS) -ftree-vectorize 
VEC_TIMEFLAGS = $(TIMEFLAGS) -ftree-vectorize 

CC = gcc


.PHONY: all_vec all_no_vec times_no_vec times_vec clean

all_no_vec: no_vec

times_no_vec: t_no_vec

all_vec: vec

times_vec: t_vec

times: exc_prefix_seq_time exc_prefix_par_time

clean:
	$(RM) task3.out

no_vec: task3.c
	$(CC) $(FLAGS) task3.c -o task3.out

vec: task3.c
	$(CC) $(VEC_FLAGS) task3.c -o task3.out

t_no_vec: task3.c
	$(CC) $(TIMEFLAGS) task3.c -o task3.out

t_vec: task3.c
	$(CC) $(VEC_TIMEFLAGS) task3.c -o task3.out

