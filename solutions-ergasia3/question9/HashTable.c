#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

/* Δημιουργία πίνακα κατακερματισμού */
HashTable *createTable(int size)
{
    HashTable *newTable = (HashTable *)malloc(sizeof(HashTable));
    newTable->table = (Entry **)malloc(size * sizeof(Entry *));
    newTable->size = size;
    newTable->n_elements = 0;
    newTable->split = 0;
    newTable->level = 0;
    for (int i = 0; i < size; i++)
    {
        newTable->table[i] = NULL;
    }
    return newTable;
}

/* Συνάρτηση κατακερματισμού */
int hash(int key, int level, int size)
{
    int divisor = size << level;
    int hashValue = key % divisor;
    if (hashValue < 0)
    {
        hashValue += divisor;
    }
    return hashValue;
}

/* Διαχωρισμός του κάδου */
void split(HashTable *hashTable)
{
    int oldBucket = hashTable->split;

    Entry *oldEntries = hashTable->table[oldBucket];
    hashTable->table[oldBucket] = NULL;

    while (oldEntries != NULL)
    {
        Entry *entry = oldEntries;
        oldEntries = oldEntries->next;
        int newBucketIndex = hash(entry->key, hashTable->level + 1, hashTable->size);
        entry->next = hashTable->table[newBucketIndex];
        hashTable->table[newBucketIndex] = entry;
    }

    hashTable->split++;
    if (hashTable->split == hashTable->size >> hashTable->level)
    {
        hashTable->split = 0;
        hashTable->level++;
    }
}

/* Εισαγωγή στον πίνακα κατακερματισμού */
void insert(HashTable *hashTable, int key, int value)
{
    int index = hash(key, hashTable->level, hashTable->size);
    if (index < hashTable->split)
    {
        index = hash(key, hashTable->level + 1, hashTable->size);
    }

    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = hashTable->table[index];
    hashTable->table[index] = newEntry;

    hashTable->n_elements++;
    if (hashTable->n_elements > hashTable->size * LOAD_FACTOR)
    {
        if (hashTable->split == 0)
        {
            hashTable->table = (Entry **)realloc(hashTable->table, (hashTable->size << 1) * sizeof(Entry *));
            for (int i = hashTable->size; i < (hashTable->size << 1); i++)
            {
                hashTable->table[i] = NULL;
            }
        }
        split(hashTable);
    }
}

/* Αναζήτηση στον πίνακα κατακερματισμού */
Entry *search(HashTable *hashTable, int key)
{
    int index = hash(key, hashTable->level, hashTable->size);
    if (index < hashTable->split)
    {
        index = hash(key, hashTable->level + 1, hashTable->size);
    }

    Entry *entry = hashTable->table[index];
    while (entry != NULL && entry->key != key)
    {
        entry = entry->next;
    }
    return entry;
}
