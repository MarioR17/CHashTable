#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    int numErrors = 0;

    // Create a hashTable of size 5
    HashTable* ht = createHashTable();

    // Make 5 keys and values to store in the hash table later
    char * keyOne = "Jade";
    char * keyTwo = "JDM";
    char * keyThree = "Mynt";
    char * keyFour = "Koda";
    char * keyFive = "Mist";

    char * valOne = "Tekken";
    char * valTwo = "Brawlhalla";
    char * valThree = "RL";
    char * valFive = "DoorDash";

    addItem(ht, keyOne, valOne); // 4 -> 4
    addItem(ht, keyTwo, valTwo); // 1 -> 1
    addItem(ht, keyThree, valThree); // 6 -> 6 (because of resize and rehash)
    addItem(ht, keyFive, valFive); // 11 -> 11

    int idxOne = getIndex(ht, keyOne);
    int idxTwo = getIndex(ht, keyTwo);
    int idxThree = getIndex(ht, keyThree);
    int idxFour = getIndex(ht, keyFour);
    int idxFive = getIndex(ht, keyFive);

    if (idxOne != 4) {
        printf("ERROR: For key \'%s\' expected an index of 4 but was instead %u\n", keyOne, idxOne);
        numErrors++;
    }
    if (idxTwo != 1) {
        printf("ERROR: For key \'%s\' expected an index of 1 but was instead %u\n", keyTwo, idxTwo);
        numErrors++;
    }
    if (idxThree != 6) {
        printf("ERROR: For key \'%s\' expected an index of 6 but was instead %u\n", keyThree, idxThree);
        numErrors++;
    }
    if (idxFour != -1) {
        printf("ERROR: For key \'%s\' expected an index -1 but was instead %u\n", keyFour, idxFour);
        numErrors++;
    }
    if (idxFive != 11) {
        printf("ERROR: For key \'%s\' expected an index of 11 but was instead %u\n", keyFive, idxFive);
        numErrors++;
    }

    if (numErrors == 0) {
        printf("All tests passed!\n");
    }

    return 0;
}
