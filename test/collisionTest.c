#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    // REMINDER WORKS ONLY IF TABLE IS SIZE 5
    // Make hash table of size 5
    HashTable * ht = createHashTable();

    // Make 5 keys and values to store in the hash table later
    char * keyOne = "Jade";
    char * keyTwo = "JDM";
    char * keyThree = "Mynt";
    char * keyFour = "Koda";
    char * keyFive = "Mist";

    char * valOne = "Tekken";
    char * valTwo = "Brawlhalla";
    char * valThree = "RL";
    char * valFour = "Persona";
    char * valFive = "DoorDash";
    

    // Hashes of respective keys in a Hash Table of 5 if it was empty
    printf("%s -> %u\n", keyOne, hashIndex(ht, keyOne)); // -> 2
    printf("%s -> %u\n", keyTwo, hashIndex(ht, keyTwo)); // -> 4
    printf("%s -> %u\n", keyThree, hashIndex(ht, keyThree)); // -> 4
    printf("%s -> %u\n", keyFour, hashIndex(ht, keyFour)); // -> 1
    printf("%s -> %u\n", keyFive, hashIndex(ht, keyFive)); // -> 0
    
    // Add the 5 items to the hash table to see if they each
    // get their own unique index
    addItem(ht, keyOne, valOne); // 2 -> 2
    addItem(ht, keyTwo, valTwo); // 4 -> 4
    addItem(ht, keyThree, valThree); // 4 -> 0
    addItem(ht, keyFour, valFour); // 1 -> 1
    addItem(ht, keyFive, valFive); // 0 -> 3
    
    // Print the hash table out
    printHashTable(ht);
}

