// hashtable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
    char * key;
    char * value;
} Item;

typedef struct {
    unsigned int size;
    unsigned int count;
    Item ** items;
} HashTable;

HashTable * createHashTable();
void deleteHashTable(HashTable * ht);
unsigned int hashIndex(HashTable * ht, const char * k);
void printHashTable(HashTable * ht);
HashTable* reHashTable(HashTable * oldHt);
void resizeHashTable(HashTable * ht);
void addItem(HashTable * ht, const char * k, const char * v);
int getIndex(HashTable * ht, char * k);
unsigned int nextPrime(unsigned int num);

#endif // HASHTABLE_H
