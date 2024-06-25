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
    //char * valFour = "SMT";
    char * valFive = "DoorDash";

    addItem(ht, keyOne, valOne); // 2 -> 2
    addItem(ht, keyTwo, valTwo); // 4 -> 4
    addItem(ht, keyThree, valThree); // 4 -> 0
    addItem(ht, keyFive, valFive); // 0 -> 1

    int idxOne = getIndex(ht, keyOne);
    int idxTwo = getIndex(ht, keyTwo);
    int idxThree = getIndex(ht, keyThree);
    int idxFour = getIndex(ht, keyFour);
    int idxFive = getIndex(ht, keyFive);

    if (idxOne != 2) {
        printf("ERROR: For key \'%s\' expected an of index 2 but was instead %u\n", keyOne, idxOne);
        numErrors++;
    }
    if (idxTwo != 4) {
        printf("ERROR: For key \'%s\' expected an of index 4 but was instead %u\n", keyTwo, idxTwo);
        numErrors++;
    }
    if (idxThree != 0) {
        printf("ERROR: For key \'%s\' expected an of index 0 but was instead %u\n", keyThree, idxThree);
        numErrors++;
    }
    if (idxFour != -1) {
        printf("ERROR: For key \'%s\' expected an of index 1 but was instead %u\n", keyFour, idxFour);
        numErrors++;
    }
    if (idxFive != 1) {
        printf("ERROR: For key \'%s\' expected an of index 3 but was instead %u\n", keyFive, idxFive);
        numErrors++;
    }

    if (numErrors == 0) {
        printf("All tests passed!\n");
    }

    return 0;
}
