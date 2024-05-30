// hashtable.c

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

static Item * createItem(const char * k, const char * v) {
    Item * i = malloc(sizeof(Item));
    i->key = strdup(k);
    i->value = strdup(v);

    return i;
}

HashTable * createHashTable() {
    HashTable * ht = malloc(sizeof(HashTable));

    ht->size = 53; 
    ht->count = 0;
    ht->items = calloc((size_t) ht->size, sizeof(Item *));

    return ht;
}

static void deleteItem(Item * i) {
    free(i->key);
    free(i->value);
    free(i);
}

void deleteHashTable(HashTable * ht) {
    for (int i = 0; i < ht->size; i++) {
        Item * item = ht->items[i]; 
        if (item != NULL) {
            deleteItem(item);
        }
    }

    free(ht->items);
    free(ht);
}

static unsigned int hashKey(const char * str) {
    unsigned int hash = 5381;

    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; 
    }

    return hash;
}

unsigned int hashedKeyIndex(const char * str) {
    unsigned int hash = hashKey(str);

    return (hash % 53);
}

void printHashTable(HashTable * ht) {
    if (ht == NULL) {
        printf("{}\n");
    } else {
        for (int i = 0; i < ht->size; i++) {
            if (i == 0) {
                printf("{%c:%c, ", *(ht->items[i]->key), *(ht->items[i]->value));
            } else if (i == ht->size - 1) {
                printf("%c:%c}", *(ht->items[i]->key), *(ht->items[i]->value));
            } else {
                printf("%c:%c, ", *(ht->items[i]->key), *(ht->items[i]->value));
            }
        }
    }   
}





