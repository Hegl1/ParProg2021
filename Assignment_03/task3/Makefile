CFLAGS = -std=gnu11 -Wall -Werror -Wextra -lm -fopenmp

.PHONY: all
all: merge_sort_seq merge_sort_par

.PHONY: clean
clean:
	$(RM) merge_sort_seq merge_sort_par

merge_sort_seq: merge_sort_seq.c
	$(CC) $(CFLAGS) merge_sort_seq.c -o merge_sort_seq

merge_sort_par: merge_sort_par.c
	$(CC) $(CFLAGS) merge_sort_par.c -o merge_sort_par