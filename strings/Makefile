CC=gcc
CFLAGS= -std=c99 -g3 -Wall -pedantic

test: test.o strings.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm -f *.o test intersection

