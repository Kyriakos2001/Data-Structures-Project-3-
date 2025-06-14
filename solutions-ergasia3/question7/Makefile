CC = gcc
CFLAGS = -Wall -g
OBJ = WeightedUndirectedGraph.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

WeightedUndirectedGraph.o: WeightedUndirectedGraph.c WeightedUndirectedGraph.h
	$(CC) $(CFLAGS) -c WeightedUndirectedGraph.c

main.o: main.c WeightedUndirectedGraph.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main
