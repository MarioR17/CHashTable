#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    HashTable *ht = createHashTable();
    char * itemOne = "abc";
    char * itemTwo = "Hello";
    char * itemThree = "Pizza";
    char * itemFour = "good evening";
    char * itemFive = "x";
    char * itemSix = "abc";

    printf("%s -> %u\n", itemOne, hashIndex(ht, itemOne));
    printf("%s -> %u\n", itemTwo, hashIndex(ht, itemTwo));
    printf("%s -> %u\n", itemThree, hashIndex(ht, itemThree));
    printf("%s -> %u\n", itemFour, hashIndex(ht, itemFour));
    printf("%s -> %u\n", itemFive, hashIndex(ht, itemFive));
    
    if (hashIndex(ht, itemOne) != hashIndex(ht, itemSix)) {
        printf(
        "ERROR: Identical keys (itemOne: %s & itemSix: %s) have different hashes\n"
        , itemOne, itemSix);
    }

    return 0;
}
