#include <stdio.h>
#include "../src/hashtable.h"

int main() {
    htHashTable * ht = htNew(); 
    htDelHashTable(ht);

    char *key = "askldlks";
    unsigned int index = hashedKeyIndex(key);

    printf("Index: %u\n", index);

    return 0;
}
