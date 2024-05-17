#include <stdio.h>
#include "../src/hashtable.h"

int main() {
    htHashTable * ht = htNew(); 
    htDelHashTable(ht);

    return 0;
}
