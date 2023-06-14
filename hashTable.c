#include "hashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t hash(size_t tamTabela, int chave) { return abs(chave) % tamTabela; }

hashTable* createHashTable(size_t tableSize) {
    struct hashTable* table;

    table = malloc(sizeof(struct hashTable));
    if (!table) return NULL;

    table->tableSize = tableSize;

    table->items = malloc(sizeof(struct nodoHash*) * tableSize);
    if (!table->items) {
        free(table);
        return NULL;
    }

    memset(table->items, 0, sizeof(struct nodoHash*) * tableSize);

    return table;
}

hashNode* insert(hashTable* table, int key) {
    hashNode *newNode, *temp, *prev;
    size_t idx;

    idx = hash(table->tableSize, key);

    if (table->items[idx]) {
        temp = table->items[idx];
        while (temp) {
            if (temp->key == key) {
                return NULL;
            }
            prev = temp;
            temp = temp->next;
        }
        temp = prev;
    }

    newNode = malloc(sizeof(hashNode));
    if (!newNode) return NULL;

    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (table->items[idx]) {
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        table->items[idx] = newNode;
    }

    return newNode;
}

void freeHashTable(hashTable* table) {
    size_t i;
    hashNode *temp, *temp2;

    for (i = 0; i < table->tableSize; i++) {
        if (table->items[i]) {
            temp = table->items[i];
            while (temp) {
                temp2 = temp->next;
                free(temp);
                temp = temp2;
            }
        }
    }

    free(table);
}

void printHashTable(hashTable* table) {
    size_t i;
    hashNode* temp;

    for (i = 0; i < table->tableSize; i++) {
        printf("%zu ", i);
        if (table->items[i]) {
            temp = table->items[i];
            while (temp) {
                printf("[%d] -> ", temp->key);
                temp = temp->next;
            }
        }
        printf("NULL");
        printf("\n");
    }
}

hashNode* search(hashTable* table, int key) {
    hashNode* temp;
    size_t idx = hash(table->tableSize, key);

    if (table->items[idx]) {
        temp = table->items[idx];
        while (temp) {
            if (temp->key == key) {
                return temp;
            }
            temp = temp->next;
        }
    }

    return NULL;
}

void delete(hashTable* table, hashNode* node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        table->items[hash(table->tableSize, node->key)] = node->next;
    }

    if (node->next) node->next->prev = node->prev;

    free(node);
}