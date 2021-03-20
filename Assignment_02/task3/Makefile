CFLAGS = -std=gnu11 -Wall -Werror -Wextra -pthread -fopenmp


.PHONY: all
all: monte_carlo_ser monte_carlo_par

.PHONY: clean
clean:
	$(RM) monte_carlo_ser monte_carlo_par

monte_carlo_ser: monte_carlo_ser.c

monte_carlo_par: monte_carlo_par.c