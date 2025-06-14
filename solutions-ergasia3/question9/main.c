#include <stdio.h>
#include "HashTable.h"

int main()
{
    HashTable *hashTable = createTable(INITIAL_SIZE);

    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 3, 30);
    insert(hashTable, 4, 40);
    insert(hashTable, 5, 50);

    Entry *result = search(hashTable, 3);
    if (result != NULL)
    {
        printf("Found key 3 with value %d\n", result->value);
    }
    else
    {
        printf("Key 3 not found\n");
    }

    result = search(hashTable, 6);
    if (result != NULL)
    {
        printf("Found key 6 with value %d\n", result->value);
    }
    else
    {
        printf("Key 6 not found\n");
    }

    return 0;
}
