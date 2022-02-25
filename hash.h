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

inline int hashCode(int key) {return abs(key) % SIZE;};

// search operation
struct dataItem* hash_sc_searchNode(int key, struct dataItem* hashArray[SIZE]);

// insert operation
int hash_sc_insertNode(struct dataItem* item, struct dataItem* hashArray[SIZE]);

// delete operation
struct dataItem* hash_sc_deleteNode(struct dataItem* item, struct dataItem* hashArray[SIZE]);

#endif /* HASHTABLE_SEPARATE_CHAINING_H_ */