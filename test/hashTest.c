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

    printf("%s -> %u\n", itemOne, hashKey(ht, itemOne));
    printf("%s -> %u\n", itemTwo, hashKey(ht, itemTwo));
    printf("%s -> %u\n", itemThree, hashKey(ht, itemThree));
    printf("%s -> %u\n", itemFour, hashKey(ht, itemFour));
    printf("%s -> %u\n", itemFive, hashKey(ht, itemFive));
    
    if (hashKey(ht, itemOne) != hashKey(ht, itemSix)) {
        printf(
        "ERROR: Identical keys (itemOne: %s & itemSix: %s) have different hashes\n"
        , itemOne, itemSix);
    }

    return 0;
}
