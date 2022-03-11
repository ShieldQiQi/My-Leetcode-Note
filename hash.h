#ifndef HASHTABLE_SEPARATE_CHAINING_H_
#define HASHTABLE_SEPARATE_CHAINING_H_

// size of hash map
#define SIZE 10000
#define true 1;
#define false 0;

// define the hash table structure
struct dataItem {
    int key;
    int value;
    struct dataItem* next;
};

inline int hashCode(int key, int size) {return abs(key) % size;};

// search operation
struct dataItem* hash_sc_searchNode(int key, struct dataItem** hashArray, int size);

// insert operation
int hash_sc_insertNode(int key, int value, struct dataItem** hashArray, int size);

// delete operation
struct dataItem* hash_sc_deleteNode(struct dataItem* item, struct dataItem** hashArray, int size);

#endif /* HASHTABLE_SEPARATE_CHAINING_H_ */