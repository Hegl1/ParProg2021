FLAGS = -std=gnu11 -Wall -Wextra -fopenmp -O1
TIMEFLAGS = -std=gnu11 -fopenmp -O1 -D TIMES

CC = gcc


.PHONY: all_vec all_no_vec times_no_vec times_no_vec_float times_no_vec_double clean

all_no_vec: no_vec

times_no_vec: t_no_vec

times_no_vec_float: t_no_vec_float

times_no_vec_double: t_no_vec_double

all_vec: vec

times_vec: t_vec

times: exc_prefix_seq_time exc_prefix_par_time

clean:
	$(RM) task2.out task2_float.out task2_double.out

no_vec: task2.c
	$(CC) $(FLAGS) task2.c -o task2.out

t_no_vec: task2.c
	$(CC) $(TIMEFLAGS) task2.c -o task2.out

t_no_vec_float: task2_float.c
	$(CC) $(TIMEFLAGS) task2_float.c -o task2_float.out

t_no_vec_double: task2_double.c
	$(CC) $(TIMEFLAGS) task2_double.c -o task2_double.out

