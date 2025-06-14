CC = gcc
CFLAGS = -Wall -g
OBJ = Graph.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

Graph.o: Graph.c Graph.h
	$(CC) $(CFLAGS) -c Graph.c

main.o: main.c Graph.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main
