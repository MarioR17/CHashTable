// hashtable.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

static htItem * htNewItem(const char * k, const char * v) {
    htItem * i = malloc(sizeof(htItem));
    i->key = strdup(k);
    i->value = strdup(v);

    return i;
}

htHashTable * htNew() {
    htHashTable * ht = malloc(sizeof(htHashTable));

    ht->size = 53; 
    ht->count = 0;
    ht->items = calloc((size_t) ht->size, sizeof(htItem *));

    return ht;
}

static void htDelItem(htItem * i) {
    free(i->key);
    free(i->value);
    free(i);
}

void htDelHashTable(htHashTable * ht) {
    for (int i = 0; i < ht->size; i++) {
        htItem * item = ht->items[i]; 
        if (item != NULL) {
            htDelItem(item);
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





