#ifndef HASHTABLE_H
#define HASHTABLE_H

#define INITIAL_SIZE 4
#define LOAD_FACTOR 0.75

typedef struct Entry
{
    int key;
    int value;
    struct Entry *next;
} Entry;

typedef struct HashTable
{
    Entry **table;
    int size;
    int n_elements;
    int split;
    int level;
} HashTable;

HashTable *createTable(int size);
int hash(int key, int level, int size);
void insert(HashTable *hashTable, int key, int value);
void split(HashTable *hashTable);
Entry *search(HashTable *hashTable, int key);

#endif
