CC=gcc
CFLAGS= -std=c99 -Wall -g3 -pedantic

# test: test.o stack.o ll.o queue.o hash_table.o 
test: test.o ll.o
	${CC} ${CFLAGS} -o $@ $^

ll.o: ll.h 
stack.o: stack.h
queue.o: queue.h ll.h
hash_table.o: hash_table.h 
tree.o: tree.h

clean: 
	rm -f test *.o 
