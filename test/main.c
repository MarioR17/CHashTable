#include "../src/hashtable.h"

int main() {
    HashTable * ht = createHashTable(); 
    deleteHashTable(ht);

    return 0;
}
