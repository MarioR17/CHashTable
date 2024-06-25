#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    // Assumes you're starting at a ht size of 5
    // Remember primes go every 3 not every one
    HashTable * ht = createHashTable();

    printf("Current ht size: %u\n", ht->size);
    
    int nextSize = nextPrime(ht->size);
    ht->size = nextSize;

    if (ht->size != 13) {
        printf("ERROR: Expected size of 13 but instead was %u\n", ht->size);
    } else {
        printf("New ht size is: %u\n", ht->size);
    }

    nextSize = nextPrime(ht->size);
    ht->size = nextSize;
    if (ht->size != 23) {
        printf("ERROR: Expected size of 23 but instead was %u\n", ht->size);
    } else {
        printf("New ht size is: %u\n", ht->size);
    }

    nextSize = nextPrime(ht->size);
    ht->size = nextSize;
    if (ht->size != 37) {
        printf("ERROR: Expected size of 37 but instead was %u\n", ht->size);
    } else {
        printf("New ht size is: %u\n", ht->size);
    }

    nextSize = nextPrime(ht->size);
    ht->size = nextSize;
    if (ht->size != 47) {
        printf("ERROR: Expected size of 47 but instead was %u\n", ht->size);
    } else {
        printf("New ht size is: %u\n", ht->size);
    }

    return 0;
}
