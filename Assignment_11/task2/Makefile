CFLAGS = -Wall -Wextra -std=gnu11 -O3
CC = gcc
C_SOURCES :=$(wildcard *.c)
C_EXECUTABLE :=$(C_SOURCES:.c=)

.PHONY: all

all:$(C_EXECUTABLE) $(CPP_EXECUTABLE)

$(C_EXECUTABLE):$(C_SOURCES)
	$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@ -lm

clean:
	rm -rf $(C_EXECUTABLE)