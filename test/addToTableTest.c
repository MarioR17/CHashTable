#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {

    HashTable * ht = createHashTable(); 

    printf("Table before adding anything: ");
    printHashTable(ht);
    printf("%d\n", ht->count);

    char * k = "Mario";
    char * v = "B";
    addItem(ht, k, v);

    printf("Table after adding one: ");
    printHashTable(ht);
    printf("%d\n", ht->count);

    char * k2 = "Jeremy";
    char * v2 = "A";
    addItem(ht, k2, v2);

    printf("Table after adding second: ");
    printHashTable(ht);
    printf("%d\n", ht->count);

    deleteHashTable(ht);

    return 0;
}
