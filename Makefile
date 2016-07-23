
CC = gcc

CFLAGS = -I.

all: romanarithmetic.o
	$(CC) -o roman romanarithmetic.o

romanarithmetic.o: romanarithmetic.c
	$(CC) $(CFLAGS) -c romanarithmetic.c

clean:
	rm roman romanarithmetic.o
