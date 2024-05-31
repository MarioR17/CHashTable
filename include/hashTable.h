// hashtable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
    char * key;
    char * value;
} Item;

typedef struct {
    int size;
    int count;
    Item ** items;
} HashTable;

HashTable * createHashTable();
void deleteHashTable(HashTable * ht);
unsigned int hashKey(const char * str);
void printHashTable(HashTable * ht);
void addItem(HashTable * ht, char * k, char * v);

#endif // HASHTABLE_H
