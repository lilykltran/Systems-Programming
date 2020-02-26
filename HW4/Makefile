# Copyright © 2018 Bart Massey

CC = gcc
CFLAGS = -Wall -g

convbits: convbits.o libbits.a
	$(CC) $(CFLAGS) -o convbits convbits.o libbits.a

libbits.a: asciitobits.o bitstoascii.o freebits.o
	-rm -f libbits.a
	ar cr -s libbits.a asciitobits.o bitstoascii.o freebits.o
	#ranlib libbits.a

convbits.o: bits.h

asciitobits.o bitstoascii.o freebits.o: bits.h

clean:
	-rm -f *.o libbits.a convbits

