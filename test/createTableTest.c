#include <stdio.h>
#include "../include/hashTable.h"

int main(void) {

    HashTable * ht = NULL;
    printf("Printing NULL table: ");
    printHashTable(ht);

    ht = createHashTable();
    printf("Printing empty table: ");
    printHashTable(ht);


    return 0;
}

