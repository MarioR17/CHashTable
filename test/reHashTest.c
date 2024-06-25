#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    unsigned int numErrors = 0;
    HashTable * ht = createHashTable();

    char * keyOne = "Kodabear"; 
    char * keyTwo = "Mikey";
    char * keyThree = "Gabe";
    char * keyFour = "Jade";
    char * keyFive = "Oscar";
    char * keySix = "Dean";
    char * keySeven = "Jakey";

    char * valueOne = "Gummy Bears";
    char * valueTwo = "Pizza";
    char * valueThree = "Burger";
    char * valueFour = "Ice cubes";
    char * valueFive = "Curry";
    char * valueSix = "Steak";
    char * valueSeven = "Chipotle";

    if (ht->size != 5) {
        printf("ERROR: Expected empty hash table to have a size 5 but instead had %u\n", ht->size);
        numErrors++;
    }

    addItem(ht, keyOne, valueOne); 
    if (ht->size != 5) {
        printf("ERROR: Expected hash table to have a size 5 but instead had %u\n", ht->size);
        numErrors++;
    }

    addItem(ht, keyTwo, valueTwo); 
    if (ht->size != 5) {
        printf("ERROR: Expected hash table to have a size 5 but instead had %u\n", ht->size);
        numErrors++;
    }

    addItem(ht, keyThree, valueThree); 
    if (ht->size != 13) {
        printf("ERROR: Expected hash table to have a size 13 but instead had %u\n", ht->size);
        numErrors++;
    }

    addItem(ht, keyFour, valueFour); 
    if (ht->size != 13) {
        printf("ERROR: Expected hash table to have a size 13 but instead had %u\n", ht->size);
        numErrors++;
    }

    addItem(ht, keyFive, valueFive); 
    if (ht->size != 13) {
        printf("ERROR: Expected hash table to have a size 13 but instead had %u\n", ht->size);
        numErrors++;
    }

    addItem(ht, keySix, valueSix); 
    if (ht->size != 13) {
        printf("ERROR: Expected hash table to have a size 13 but instead had %u\n", ht->size);
        numErrors++;
    }

    addItem(ht, keySeven, valueSeven); 
    if (ht->size != 23) {
        printf("ERROR: Expected hash table to have a size 23 but instead had %u\n", ht->size);
        numErrors++;
    }

    if (numErrors == 0) {
        printf("All tests passed!\n");
    }

    return 0;
}
