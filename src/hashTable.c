// hashtable.c

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hashTable.h"

static Item * createItem(const char * k, const char * v) {
    Item * i = NULL;

    if (k != NULL && v != NULL) {
        i = malloc(sizeof(Item));
        if (i == NULL) {
            printf("ERROR: Unable to allocate memory for item\n");
            exit(1);
        }

        i->key = strdup(k);
        if (i->key == NULL) {
            printf("ERROR: Unable to allocate memory for item's key\n");
            exit(1);
        }

        i->value = strdup(v);
        if (i->value == NULL) {
            printf("ERROR: Unable to allocate memory for item's value\n");
            exit(1);
        }
    }

    return i;
}

HashTable * createHashTable(void) {
    HashTable * ht = malloc(sizeof(HashTable));

    if (ht == NULL) {
        printf("ERROR: Unable to allocate memory for hash table\n");
        exit(1);
    }

    ht->size = 5; 
    ht->count = 0;

    ht->items = calloc((size_t) ht->size, sizeof(Item *));
    if (ht->items == NULL) {
        printf("ERROR: Unable to allocate memory for hash table items\n");
        exit(1);
    }

    return ht;
}

static void deleteItem(Item * i) {
    if (i != NULL) {
        free(i->key);
        free(i->value);
        free(i);
    }
}

void deleteHashTable(HashTable * ht) {
    if (ht != NULL) {
        for (unsigned int i = 0; i < ht->size; i++) {
            Item * item = ht->items[i]; 
            if (item != NULL) {
                deleteItem(item);
            }
        }

        free(ht->items);
        free(ht);
    }
}

static unsigned int hashKey(HashTable * ht, const char * str) {
    unsigned int hash = 5381;

    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; 
    }

    return (hash % (ht->size));
}

unsigned int hashIndex(HashTable * ht, const char * k) {
    unsigned int hash = hashKey(ht, k);
    while (ht->items[hash] != NULL) {
        if (hash == (ht->size - 1)) {
            hash = 0;
        } else {
            hash++;
        }
    }

    return hash;
}

void addItem(HashTable * ht, const char * k, const char * v) {
    if (ht != NULL) {
        Item * item = createItem(k, v);

        if (item != NULL) {
            unsigned int keyHash = hashIndex(ht, k);;
            ht->items[keyHash] = item;
            ht->count++;
        } else {
            deleteItem(item);
        }
    }
}

void printHashTable(HashTable * ht) {
    if (ht == NULL) {
        printf("{}\n");
    } else {
        printf("{ ");
        for (unsigned int i = 0; i < ht->size; i++) {
            if (ht->items[i] != NULL) {
                printf("%s:%s, ", ht->items[i]->key, ht->items[i]->value);
            }
        }
        printf("}\n");
    }   
}

