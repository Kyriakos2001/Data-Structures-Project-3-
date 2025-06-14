CC=gcc
CFLAGS=-Wall -g
OBJ=UndirectedGraph.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

UndirectedGraph.o: UndirectedGraph.c GraphTypes.h
	$(CC) $(CFLAGS) -c UndirectedGraph.c

main.o: main.c GraphTypes.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main
