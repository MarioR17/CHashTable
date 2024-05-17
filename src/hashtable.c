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



