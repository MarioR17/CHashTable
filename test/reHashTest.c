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

    printf("%s\n", keyOne);
    printf("%s\n", keyTwo);
    printf("%s\n", keyThree);
    printf("%s\n", keyFour);
    printf("%s\n", keyFive);
    printf("%s\n", keySix);
    printf("%s\n", keySeven);
    printf("%s\n", keyEight);

    printf("%s\n", valueOne);
    printf("%s\n", valueTwo);
    printf("%s\n", valueThree);
    printf("%s\n", valueFour);
    printf("%s\n", valueFive);
    printf("%s\n", valueSix);
    printf("%s\n", valueSeven);
    printf("%s\n", valueEight);

    printHashTable(ht);

    return 0;
}
