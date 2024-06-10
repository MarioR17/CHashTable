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
unsigned int hashKey(HashTable * ht, const char * str);
void printHashTable(HashTable * ht);
void addItem(HashTable * ht, char * k, char * v);

#endif // HASHTABLE_H
