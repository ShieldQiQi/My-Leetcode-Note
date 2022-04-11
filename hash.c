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
struct dataItem* hash_sc_deleteNode(struct dataItem* item, struct dataItem** hashArray, int size)
{
    int hashIndex = hashCode(item->key, size);
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
    } else if(preTemp != temp) {
        preTemp->next = NULL;
    } else {
        hashArray[hashIndex] = NULL;
    }
    
    return temp;
}