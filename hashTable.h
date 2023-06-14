#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

typedef struct hashNode {
    int key;
    struct hashNode* next;
    struct hashNode* prev;
} hashNode;

typedef struct hashTable {
    size_t tableSize;
    hashNode** items;
} hashTable;

hashTable* createHashTable(size_t tableSize);

hashNode* insert(hashTable* table, int key);

void freeHashTable(hashTable* table);

void printHashTable(hashTable* table);

hashNode* search(hashTable* table, int key);

void delete(hashTable* table, hashNode* node);

#endif