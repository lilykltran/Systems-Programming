CC=gcc
CFLAGS=-g
DFLAGS=
PROGS= fp_parse

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@ -lm

clean:
	rm -f $(PROGS) *.o ~*

