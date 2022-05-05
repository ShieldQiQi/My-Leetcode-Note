#ifndef HASHTABLE_SEPARATE_CHAINING_H_
#define HASHTABLE_SEPARATE_CHAINING_H_

#define true 1;
#define false 0;

/*
 * hash table integer as the number
 */

// define the hash table structure
struct dataItem {
    int key;
    int value;
    struct dataItem* next;
};
// init hashTable
struct dataItem** initHashTable(int size);
inline int hashCode(int key, int size) {return abs(key) % size;};
// search operation
struct dataItem* hash_sc_searchNode(int key, struct dataItem** hashArray, int size);
// insert operation
int hash_sc_insertNode(int key, int value, struct dataItem** hashArray, int size);
// delete operation
struct dataItem* hash_sc_deleteNode(int key, struct dataItem** hashArray, int size);
// travel
void hash_sc_travel(int (*nums)[2], struct dataItem** hashArray, int size);

/*
 * hash table string as the key
 */

// define the hash table structure
struct dataItem2 {
    char *key;
    char *value;
    struct dataItem2* next;
};
// init hashTable
struct dataItem2** initHashTable2(int size);
int hashCode2(char *key, int size);
// search operation
struct dataItem2* hash_sc_searchNode2(char *key, struct dataItem2** hashArray, int size);
// insert operation
int hash_sc_insertNode2(char *key, char *value, struct dataItem2** hashArray, int size);
// delete operation
struct dataItem2* hash_sc_deleteNode2(struct dataItem2* item, struct dataItem2** hashArray, int size);
// travel
void hash_sc_travel2(char* (*string)[2], struct dataItem2** hashArray, int size);


#endif /* HASHTABLE_SEPARATE_CHAINING_H_ */