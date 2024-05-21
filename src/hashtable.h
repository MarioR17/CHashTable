// hashtable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
    char * key;
    char * value;
} htItem;

typedef struct {
    int size;
    int count;
    htItem ** items;
} htHashTable;

htHashTable * htNew();
void htDelHashTable(htHashTable * ht);
unsigned int hashedKeyIndex(const char * str);

#endif // HASHTABLE_H
