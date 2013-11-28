CC=gcc
CFLAGS= -g3 -Wall -std=c99 -pedantic 

test: test.o bit_ops.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm -f test bit_ops *.o 
