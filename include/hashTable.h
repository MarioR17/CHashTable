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
void addItem(HashTable * ht, const char * k, const char * v);
unsigned int getIndex(HashTable * ht, char * k);

#endif // HASHTABLE_H
