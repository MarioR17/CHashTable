#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    char * itemOne = "abc";
    char * itemTwo = "Hello";
    char * itemThree = "Pizza";
    char * itemFour = "good evening";
    char * itemFive = "x";
    char * itemSix = "abc";

    printf("%s -> %u\n", itemOne, hashKey(itemOne));
    printf("%s -> %u\n", itemTwo, hashKey(itemTwo));
    printf("%s -> %u\n", itemThree, hashKey(itemThree));
    printf("%s -> %u\n", itemFour, hashKey(itemFour));
    printf("%s -> %u\n", itemFive, hashKey(itemFive));
    
    if (hashKey(itemOne) != hashKey(itemSix)) {
        printf(
        "ERROR: Identical keys (itemOne: %s & itemSix: %s) have different hashes\n"
        , itemOne, itemSix);
    }

    return 0;
}
