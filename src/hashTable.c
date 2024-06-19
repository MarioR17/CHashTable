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

void addItem(HashTable * ht, const char * k, const char * v) {
    if (ht != NULL) {
        Item * item = createItem(k, v);

        if (item != NULL) {
            if (ht->count >= (ht->size / 2)) {
                //puts("printing old in add item b4 rehashing");
                printHashTable(ht);
                reHashTable(ht);
                //puts("printing new in add item after rehashing");
                unsigned int keyHash = hashIndex(ht, k);
                ht->items[keyHash] = item;
                ht->count++;
            } else {
                //puts("heh... hey");
                unsigned int keyHash = hashIndex(ht, k);
                ht->items[keyHash] = item;
                ht->count++;
            }
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

void resizeHashTable(HashTable * ht) {
    unsigned int nextSize = nextPrime(ht->size);
    printf("%u\n", ht->size);
    ht->size = nextSize;
    printf("%p\n", ht->items);
    ht->items = realloc(ht->items, ht->size);
    printf("%u\n", ht->size);
    printf("%p\n", ht->items);
    printHashTable(ht);
    addItem(ht, "Gabe", "Slate");
    printHashTable(ht);
    
    if (ht->items == NULL) {
        printf("ERROR: Unable to allocate memory for hash table items\n");
        exit(1);
    }
}

void reHashTable(HashTable * oldHt) {
    HashTable * newHt = createHashTable();
    //puts("AB to print in rehash (new then old)");
    printHashTable(oldHt);
    newHt->size = oldHt->size;
    resizeHashTable(newHt);
    puts("Next should be empty");
    addItem(newHt, "Gage", "Needs");
    printHashTable(newHt);
    printHashTable(oldHt);
    //printf("%u\n", oldHt->size);
    //printf("%u\n", newHt->size);

    //puts("Starting");
    //printf("%u\n", newHt->count);
    for (unsigned int i = 0; i < oldHt->size; i++) {
        if (oldHt->items[i] != NULL) {
            //printf("Item %u's key: %s\n", i, oldHt->items[i]->key);
            //printf("Item %u's value: %s\n", i, oldHt->items[i]->value);
            addItem(newHt, oldHt->items[i]->key, oldHt->items[i]->value);
            //printf("%u\n", newHt->count);
        }
    }
    puts("Trying print");
    printHashTable(oldHt);
    printf("%u\n", newHt->size);
    printf("%u\n", newHt->count);
    printHashTable(newHt);
    deleteHashTable(oldHt);

    oldHt = newHt;
}



