CFLAGS := -ggdb3 -O2 -Wall -Wextra -std=c11
CFLAGS += -Wmissing-prototypes
CPPFLAGS := -D_POSIX_C_SOURCE=200809L

PROGS := pingpong primes xargs

all: $(PROGS)

xargs: xargs.o
primes: primes.o
pingpong: pingpong.o

clean:
	rm -f $(PROGS) *.o core vgcore.*

.PHONY: clean all
