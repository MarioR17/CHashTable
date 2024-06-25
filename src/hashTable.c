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
            if (ht->items[i] != NULL) {
                deleteItem(ht->items[i]);
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

static void resizeHashTable(HashTable * ht) {
    unsigned int originalSize = ht->size;   
    unsigned int newSize = nextPrime(originalSize);    
    ht->size = newSize;

    Item ** oldItems = ht->items;
    Item ** newItems = calloc((size_t) newSize, sizeof(Item *));
    ht->items = newItems;

    if (newItems == NULL) {
        printf("ERROR: Could not allocate memory for new items array\n");
        exit(1);
    }

    for (unsigned int i = 0; i < originalSize; i++) {
        if (oldItems[i] != NULL) {
            char * newKey = strdup(oldItems[i]->key);
            char * newValue = strdup(oldItems[i]->value);
            Item * item = createItem(newKey, newValue);

            if (item == NULL) {
                printf("ERROR: Could not allocate memory for item in newItems\n");
                free(newKey);
                free(newValue);
                deleteHashTable(ht);
                deleteItem(item);
                exit(1);
            }
            
            unsigned int keyHash = hashIndex(ht, newKey);
            ht->items[keyHash] = item;
        }
    }

    for (unsigned int i = 0; i < originalSize; i++) {
        deleteItem(oldItems[i]);
    }

    free(oldItems);
}


void addItem(HashTable * ht, const char * k, const char * v) {
    if (ht != NULL) {
        Item * item = createItem(k, v);

        if (item != NULL) {
            if (ht->count >= (ht->size / 2)) {
                resizeHashTable(ht);
            }
            unsigned int keyHash = hashIndex(ht, k);
            ht->items[keyHash] = item;
            ht->count++;
        } else {
            deleteItem(item);
        }
    }
}

void printHashTable(HashTable * ht) {
    if (ht == NULL || ht->items == NULL) {
        printf("{}\n");
    } else {
        unsigned int currCount = 0;
        printf("{ ");
        for (unsigned int i = 0; i < ht->size && currCount < ht->count; i++) {
            if (ht->items[i] != NULL) {
                currCount++;
                printf("%s:%s, ", ht->items[i]->key, ht->items[i]->value);
            }
        }
        printf("}\n");
    }   
}

int getIndex(HashTable * ht, char * k) {
    int done = 0;
    unsigned int idx = hashKey(ht, k);

    if (ht->items[idx] == NULL) {
        return -1;
    }

    while (!done) {
        if (ht->items[idx] == NULL) {
            return -1;
        }

        if (strcmp(ht->items[idx]->key, k) != 0) {
            if (idx == (ht->size - 1)) {
                idx = 0;
            } else {
                idx++;
            }
        } else {
            done = 1;
        }
    }

    return idx;
}

static unsigned int isPrime(const unsigned int num) {
    for (unsigned int i = 2; i < num; i++) { 
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

unsigned int nextPrime(unsigned int num) {
    int done = 0;
    int next = 0;
    num++;

    while (done < 3) {
        if (isPrime(num)) {
            next = num;
            done++;
        } 
        num++;
    }

    return next;
}
