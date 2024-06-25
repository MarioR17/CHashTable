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
                HashTable * newHt = reHashTable(ht);
                puts("print after rehash apparently");
                printf("%u\n", newHt->size);
                printf("%u\n", newHt->count);
                printHashTable(newHt);
                //puts("printing new in add item after rehashing");
                unsigned int keyHash = hashIndex(newHt, k);
                newHt->items[keyHash] = item;
                newHt->count++;
            } else {
                //puts("heh... hey");
                unsigned int keyHash = hashIndex(ht, k);
                printf("%s's key hash: %u\n", k, keyHash);
                ht->items[keyHash] = item;
                printf("%s:%s\n", ht->items[keyHash]->key, ht->items[keyHash]->value);
                ht->count++;
                printf("ht count: %u\n", ht->count);
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
        puts("Incoming");
        if (*(ht->items[10]->key) == '\0' || *(ht->items[10]->value) == '\0') {
            puts("Brotha");
        }
        printf("%s:%s, ", ht->items[5]->key, ht->items[5]->value);
        unsigned int currCount = 0;
        printf("ht size: %u\n", ht->size);
        printf("ht count: %u\n", ht->count);
        printf("{ ");
        for (unsigned int i = 0; i < ht->size && currCount < ht->count; i++) {
            if (ht->items[i] != NULL) {
                currCount++;
                printf("%u\n", i);
                if (ht->items[i]->key == NULL || ht->items[i]->value == NULL) {
                    puts("Brotha");
                }
                printf("%s:%s, ", ht->items[i]->key, ht->items[i]->value);
                puts("Test2");
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
    ht->items = realloc(ht->items, ht->size * sizeof(Item *));
        
    if (ht->items == NULL) {
        printf("ERROR: Unable to allocate memory for hash table items\n");
        exit(1);
    }
    printf("%u\n", ht->size);
    printf("%p\n", ht->items);
    /*
    puts("should break right about now");
    printHashTable(ht);
    addItem(ht, "Gabe", "Slate");
    printHashTable(ht);
    */
}

HashTable * reHashTable(HashTable * oldHt) {
    HashTable * newHt = createHashTable();
    //puts("AB to print in rehash (new then old)");
    printHashTable(oldHt);
    printHashTable(newHt);
    newHt->size = oldHt->size;
    puts("Koda");
    printHashTable(newHt);
    resizeHashTable(newHt);
    puts("Mikey");
    printHashTable(newHt);
    puts("Next should be empty");
    addItem(newHt, "Gage", "Needs");
    printHashTable(newHt);
    puts("Test");
    //printf("%u\n", oldHt->size);
    //printf("%u\n", newHt->size);

    puts("Starting");
    printf("%u\n", newHt->count);
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
    //printHashTable(newHt);
    deleteHashTable(oldHt);

    return newHt;
}


