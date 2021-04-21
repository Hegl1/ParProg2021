CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -Ofast
CC = gcc-10

.PHONY: all
all: delannoy_ser delannoy_stupid

.PHONY: times
times: delannoy_ser_time delannoy_stupid_time

.PHONY: clean
clean:
	$(RM) delannoy_ser.out delannoy_stupid.out

delannoy_ser: Delannoy_ser.c
	$(CC) $(CFLAGS) Delannoy_ser.c -o delannoy_ser.out

delannoy_stupid: Delannoy_ser_stupid.c
	$(CC) $(CFLAGS) Delannoy_ser_stupid.c -o delannoy_stupid.out

delannoy_ser_time: Delannoy_ser.c
	$(CC) $(CFLAGS) -D TIME Delannoy_ser.c -o delannoy_ser.out

delannoy_stupid_time: Delannoy_ser_stupid.c
	$(CC) $(CFLAGS) -D TIME Delannoy_ser_stupid.c -o delannoy_stupid.out

