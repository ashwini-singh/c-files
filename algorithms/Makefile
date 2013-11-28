CC=gcc
CFLAGS= -g3 -Wall -std=c99 -pedantic

sort: sort.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm -f sort *.o
