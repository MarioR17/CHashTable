#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    // Assumes you're starting at a ht size of 5
    HashTable * ht = createHashTable();

    printf("Current ht size: %u\n", ht->size);
    
    int nextSize = nextPrime(ht->size);
    ht->size = nextSize;

    if (ht->size != 7) {
        printf("ERROR: Expected size of 7 but instead was %u\n", ht->size);
    } else {
        printf("New ht size is: %u\n", ht->size);
    }

    nextSize = nextPrime(ht->size);
    ht->size = nextSize;
    if (ht->size != 11) {
        printf("ERROR: Expected size of 11 but instead was %u\n", ht->size);
    } else {
        printf("New ht size is: %u\n", ht->size);
    }

    nextSize = nextPrime(ht->size);
    ht->size = nextSize;
    if (ht->size != 13) {
        printf("ERROR: Expected size of 13 but instead was %u\n", ht->size);
    } else {
        printf("New ht size is: %u\n", ht->size);
    }

    nextSize = nextPrime(ht->size);
    ht->size = nextSize;
    if (ht->size != 17) {
        printf("ERROR: Expected size of 17 but instead was %u\n", ht->size);
    } else {
        printf("New ht size is: %u\n", ht->size);
    }

    return 0;
}
