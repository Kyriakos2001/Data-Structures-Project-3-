CC=gcc
CFLAGS=-Wall -g
OBJ=DirectedGraph.o Queue.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

DirectedGraph.o: DirectedGraph.c GraphTypes.h Queue.h
	$(CC) $(CFLAGS) -c DirectedGraph.c

Queue.o: Queue.c Queue.h GraphTypes.h
	$(CC) $(CFLAGS) -c Queue.c

main.o: main.c GraphTypes.h Queue.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main
