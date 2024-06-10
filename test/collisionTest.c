#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {
    /*
    printf("%s -> %u\n", "Jade", hashKey("Jade")); -> 2
    printf("%s -> %u\n", "JDM", hashKey("JDM")); -> 4
    printf("%s -> %u\n", "Mynt", hashKey("Mynt")); -> 4
    printf("%s -> %u\n", "Koda", hashKey("Koda")); -> 1
    printf("%s -> %u\n", "Mist", hashKey("Mist")); -> 0
    */
    HashTable * ht = createHashTable();
    addItem(ht, "Jade", "Tekken");
    addItem(ht, "JDM", "Brawl");
    addItem(ht, "Koda", "Persona");
    addItem(ht, "Mist", "Rocket League");
    addItem(ht, "Mynt", "RL");
    printHashTable(ht);
}

