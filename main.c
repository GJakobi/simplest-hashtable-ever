#include <stdio.h>

#include "hashTable.h"

int main() {
    int exit = 0, key;
    char command;
    size_t tableSize;
    hashTable* table;
    hashNode* temp;


    scanf("%zu", &tableSize);

    table = createHashTable(tableSize);

    while (!exit) {
        scanf(" %c", &command);
        switch (command) {
            case 'i':
                scanf("%d", &key);
                temp = insert(table, key);
                if (!temp) printf("Error inserting %d.\n", key);
                break;
            case 'r':
                scanf("%d", &key);
                temp = search(table, key);
                if (temp) {
                    delete(table, temp);
                } else {
                    printf("Error removing %d.\n", key);
                }
                break;
            case 'b':
                scanf("%d", &key);
                temp = search(table, key);
                if (temp) {
                    printf("Found %d.\n", key);
                } else {
                    printf("Not found %d.\n", key);
                }
                break;
            case 'l':
                printHashTable(table);
                break;
            case 'f':
                freeHashTable(table);
                exit = 1;
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}
