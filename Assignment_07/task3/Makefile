FLAGS = -std=gnu11 -Wall -Wextra -fopenmp -O1
TIMEFLAGS = -std=gnu11 -fopenmp -O1 -D TIMES

CC = gcc


.PHONY: all clean times

all: no_times

times: time

times_no_vec: t_no_vec

clean:
	$(RM) task3.out

no_times: task3.c
	$(CC) $(FLAGS) task3.c -o task3.out

time: task3.c
	$(CC) $(TIMEFLAGS) task3.c -o task3.out

