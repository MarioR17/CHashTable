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

    char * valueOne = "Gummy Bears";
    char * valueTwo = "Pizza";
    char * valueThree = "Burger";
    char * valueFour = "Ice cubes";
    char * valueFive = "Curry";
    char * valueSix = "Steak";
    char * valueSeven = "Chipotle";

    puts("Empty Hash Table:");
    printHashTable(ht);

    addItem(ht, keyOne, valueOne);
    puts("Hash Table after adding one Item:");
    printHashTable(ht);

    addItem(ht, keyTwo, valueTwo);
    puts("Hash Table after adding two Items:");
    printHashTable(ht);
    printf("Hash Table size after two items being added: %u\n", ht->size);

    addItem(ht, keyThree, valueThree);
    puts("Hash Table after adding three Items:");
    printHashTable(ht);
    printf("Hash Table size after three items being added: %u\n", ht->size);

    addItem(ht, keyFour, valueFour);
    puts("Hash Table after adding four Items:");
    printHashTable(ht);
    printf("Hash Table size after four items being added: %u\n", ht->size);


    addItem(ht, keyFive, valueFive);
    puts("Hash Table after adding five Items:");
    printHashTable(ht);
    printf("Hash Table size after five items being added: %u\n", ht->size);
    printf("Count after five items: %u\n", ht->count);

    addItem(ht, keySix, valueSix);
    puts("Hash Table after adding Six Items:");
    printHashTable(ht);
    printf("Hash Table size after six items being added: %u\n", ht->size);
    printf("Count after six items: %u\n", ht->count);


    addItem(ht, keySeven, valueSeven);
    puts("Hash Table after adding Seven Items:");
    printHashTable(ht);
    printf("Hash Table size after seven items being added: %u\n", ht->size);
    printf("Count after seven items: %u\n", ht->count);

    return 0;
}
