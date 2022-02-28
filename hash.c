/*
 * Hash table test demo using separate chaining method
 * Author: XiaoFang Qi
 * Date: 2022/2/23
 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

// size of hash map

//struct dataItem* hashArray[SIZE];

// search Item by key
struct dataItem* hash_sc_searchNode(int key, struct dataItem* hashArray[SIZE])
{
    int hashIndex = hashCode(key);
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
int hash_sc_insertNode(struct dataItem* item, struct dataItem* hashArray[SIZE])
{
    int hashIndex = hashCode(item->key);
    if(hashArray[hashIndex]==NULL)
    {
        hashArray[hashIndex] = (struct dataItem*)malloc(sizeof(struct dataItem));
        hashArray[hashIndex]->key = item->key;
        hashArray[hashIndex]->value = item->value;
        hashArray[hashIndex]->next = NULL;
        return 1;
    }

    struct dataItem* temp = hashArray[hashIndex];
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (struct dataItem*)malloc(sizeof(struct dataItem));
    temp->next->key = item->key;
    temp->next->value = item->value;
    temp->next->next = NULL;
    return 1;

}

// delete Item operation
struct dataItem* hash_sc_deleteNode(struct dataItem* item, struct dataItem* hashArray[SIZE])
{
    int hashIndex = hashCode(item->key);
    struct dataItem* temp = hashArray[hashIndex];
    struct dataItem* preTemp = temp;
    while(temp->key != item->key)
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
    } else {
        preTemp->next = NULL;
    }
    
    return temp;
}