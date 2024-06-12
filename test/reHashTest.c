#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    HashTable * ht = createHashTable();

    char * keyOne = "Kodabear"; 
    char * keyTwo = "Mikey";
    char * keyThree = "Gabe";
    char * keyFour = "Jade";
    char * keyFive = "Oscar";
    char * keySix = "Dean";
    char * keySeven = "Jakey";
    char * keyEight = "Chip";

    char * valueOne = "Gummy Bears";
    char * valueTwo = "Pizza";
    char * valueThree = "Burger";
    char * valueFour = "Ice cubes";
    char * valueFive = "Curry";
    char * valueSix = "Steak";
    char * valueSeven = "Chipotle";
    char * valueEight = "Tacos";

    printf("Current ht size: %u\n", ht->size);

    addItem(ht, keyOne, valueOne);
    printHashTable(ht);
    addItem(ht, keyTwo, valueTwo);
    printHashTable(ht);
    printf("ht size: %u\n", ht->size);
    addItem(ht, keyThree, valueThree);
    printf("ht size: %u\n", ht->size);
    addItem(ht, keyFour, valueFour);
    printf("ht size: %u\n", ht->size);
    addItem(ht, keyFive, valueFive);
    printf("ht size: %u\n", ht->size);
    addItem(ht, keySix, valueSix);
    printf("ht size: %u\n", ht->size);
    addItem(ht, keySeven, valueSeven);
    printf("ht size: %u\n", ht->size);
    addItem(ht, keyEight, valueEight);
    printf("ht size: %u\n", ht->size);
    printHashTable(ht);

    return 0;
}
