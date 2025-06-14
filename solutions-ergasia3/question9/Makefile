CC = gcc
CFLAGS = -Wall -g
OBJ = HashTable.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

HashTable.o: HashTable.c HashTable.h
	$(CC) $(CFLAGS) -c HashTable.c

main.o: main.c HashTable.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main
