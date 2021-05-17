FLAGS = -std=gnu11 -Wall -Wextra -pedantic -fopenmp
FLAGSOMP = -std=gnu11 -Wall -Wextra -pedantic -fopenmp
FLAGSAUTOPAR = -std=gnu11 -Wall -Wextra -pedantic -fopenmp -ftree-parallelize-loops=4

CC = gcc

.PHONY: all clean snippit1 snippit1_omp snippit1_autopar snippit2 snippit3

all: snippit1 snippit1_omp snippit1_autopar snippit2 snippit3

clean:
	$(RM) snippit1.out snippit1_omp.out snippit1_autopar.out snippit2.out snippit3.out

snippit1: snippit1.c
	$(CC) $(FLAGSOMP) snippit1.c -o snippit1.out

snippit1_omp: snippit1_omp.c
	$(CC) $(FLAGSOMP) snippit1_omp.c -o snippit1_omp.out

snippit1_autopar: snippit1.c
	$(CC) $(FLAGSAUTOPAR) snippit1.c -o snippit1_autopar.out

snippit2: snippit2.c
	$(CC) $(FLAGS) snippit2.c -o snippit2.out

snippit3: snippit3.c
	$(CC) $(FLAGS) snippit3.c -o snippit3.out
