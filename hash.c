/*
 * Hash table test demo using separate chaining method
 * Author: XiaoFang Qi
 * Date: 2022/2/23
 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <string.h>

/*
 * hash table integer as the number
 */

// init hashTable
struct dataItem** initHashTable(int size)
{
    struct dataItem** hashTable = (struct dataItem**)malloc(sizeof(struct dataItem*)*size);
    for(int i=0; i<size; i++)
        hashTable[i] = NULL;
    return hashTable;
}

// search Item by key
struct dataItem* hash_sc_searchNode(int key, struct dataItem** hashArray, int size)
{
    int hashIndex = hashCode(key, size);
    struct dataItem* temp = hashArray[hashIndex];
    while(temp != NULL)
    {
        if(temp->key == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// insert Item operation
int hash_sc_insertNode(int key, int value, struct dataItem** hashArray, int size)
{
    int hashIndex = hashCode(key, size);
    if(hashArray[hashIndex]==NULL)
    {
        hashArray[hashIndex] = (struct dataItem*)malloc(sizeof(struct dataItem));
        hashArray[hashIndex]->key = key;
        hashArray[hashIndex]->value = value;
        hashArray[hashIndex]->next = NULL;
        return 1;
    }

    struct dataItem* temp = hashArray[hashIndex];
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (struct dataItem*)malloc(sizeof(struct dataItem));
    temp->next->key = key;
    temp->next->value = value;
    temp->next->next = NULL;
    return 1;

}

// delete Item operation
struct dataItem* hash_sc_deleteNode(int key, struct dataItem** hashArray, int size)
{
    int hashIndex = hashCode(key, size);
    struct dataItem* temp = hashArray[hashIndex];
    struct dataItem* preTemp = temp;
    if(temp == NULL)
        return NULL;
    while(temp->key != key)
    {
        if(temp->next != NULL){
            preTemp = temp;
            temp = temp->next;
        }else {
            return false;
        }
    }
    // delete the linked node
    if(temp->next != NULL)
    {
        if(preTemp != temp)
        {
            preTemp->next = temp->next;
        } else {
            hashArray[hashIndex] = temp->next;
        }
    } else if(preTemp != temp) {
        preTemp->next = NULL;
    } else {
        hashArray[hashIndex] = NULL;
    }
    
    return temp;
}

// travel Item operation
void hash_sc_travel(int (*nums)[2], struct dataItem** hashArray, int size)
{
    int count = 0;
    for(int i=0; i<size; i++)
    {
        struct dataItem* temp = hashArray[i];
        while(temp != NULL)
        {
            nums[count][0] = temp->value;
            nums[count][1] = temp->key;
            count++;
            temp = temp->next;
        }
    }
}

/*
 * hash table string as the key
 */

// init hashTable
struct dataItem2** initHashTable2(int size)
{
    struct dataItem2** hashTable = (struct dataItem2**)malloc(sizeof(struct dataItem2*)*size);
    for(int i=0; i<size; i++)
        hashTable[i] = NULL;
    return hashTable;
}
int hashCode2(char *key, int size)
{
    unsigned int h = 0;
    for(int i=0; key[i]; i++)
        h = key[i] + 31*h;
    return h % size;
}
// search operation
struct dataItem2* hash_sc_searchNode2(char *key, struct dataItem2** hashArray, int size)
{
    int hashIndex = hashCode2(key, size);
    struct dataItem2* temp = hashArray[hashIndex];
    while(temp != NULL)
    {
        if(strcmp(temp->key, key) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
// insert operation
int hash_sc_insertNode2(char *key, char *value, struct dataItem2** hashArray, int size)
{
    int hashIndex = hashCode2(key, size);
    if(hashArray[hashIndex]==NULL)
    {
        hashArray[hashIndex] = (struct dataItem2*)malloc(sizeof(struct dataItem2));
        hashArray[hashIndex]->key = key;
        hashArray[hashIndex]->value = value;
        hashArray[hashIndex]->next = NULL;
        return true;
    }

    struct dataItem2* temp = hashArray[hashIndex];
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (struct dataItem2*)malloc(sizeof(struct dataItem2));
    temp->next->key = key;
    temp->next->value = value;
    temp->next->next = NULL;
    return true;
}
// delete operation
struct dataItem2* hash_sc_deleteNode2(struct dataItem2* item, struct dataItem2** hashArray, int size)
{
    int hashIndex = hashCode2(item->key, size);
    struct dataItem2* temp = hashArray[hashIndex];
    struct dataItem2* preTemp = temp;
    if(temp == NULL)
        return NULL;
    while(strcmp(temp->key, item->key) != 0)
    {
        if(temp->next != NULL){
            preTemp = temp;
            temp = temp->next;
        }else {
            return NULL;
        }
    }
    // delete the linked node
    if(temp->next != NULL)
    {
        if(preTemp != temp)
        {
            preTemp->next = temp->next;
        } else {
            hashArray[hashIndex] = temp->next;
        }
    } else if(preTemp != temp) {
        preTemp->next = NULL;
    } else {
        hashArray[hashIndex] = NULL;
    }
    
    return temp;
}
// travel
void hash_sc_travel2(char* (*string)[2], struct dataItem2** hashArray, int size)
{
    int count = 0;
    for(int i=0; i<size; i++)
    {
        struct dataItem2* temp = hashArray[i];
        while(temp != NULL)
        {
            string[count][0] = temp->value;
            string[count][1] = temp->key;
            count++;
            temp = temp->next;
        }
    }
}