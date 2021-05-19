FLAGS = -std=gnu11 -Wall -Wextra -fopenmp -O1
CC = gcc


.PHONY: all clean times

all: snp1_nt snp2_nt snp3_nt

times: snp1_t snp2_t snp3_t

clean:
	$(RM) snippet1.out snippet2.out snippet3.out

snp1_nt: snippet1.c
	$(CC) $(FLAGS) snippet1.c -o snippet1.out

snp2_nt: snippet2.c
	$(CC) $(FLAGS) snippet2.c -o snippet2.out

snp3_nt: snippet3.c
	$(CC) $(FLAGS) snippet3.c -o snippet3.out

